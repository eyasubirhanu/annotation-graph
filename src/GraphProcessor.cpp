/**
Created by Abdulrahman Semrie<hsamireh@gmail.com> on 10/2/20
Copyright © 2020 Abdulrahman Semrie
This file is part of MOZI-AI Annotation Scheme
Annotation Graph is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.
This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this software.  If not, see
<http://www.gnu.org/licenses/>.
**/

//
#include "GraphProcessor.h"
#include "Utils.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cstdio>
#include <iostream>
#include <rapidjson/filereadstream.h>
#include <rapidjson/filewritestream.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

namespace annotation_graph {

string GraphProcessor::processGraph() {
  // Parse Json
  if (!parseJSON()) {
    throw std::runtime_error(
        "Couldn't parse the json file. Make sure the file exists ");
  }

  // Separate the graph into GO and nonGO subgraphs
  Graph graph;
  GraphAttributes graphAttr(
      graph, GraphAttributes::nodeGraphics | GraphAttributes::nodeId |
                 GraphAttributes::edgeGraphics | GraphAttributes::nodeLabel |
                 GraphAttributes::edgeLabel | GraphAttributes::edgeType |
                 GraphAttributes::edgeStyle | GraphAttributes::nodeStyle);
  NodeInfos NodeInfos;
  EdgeInfos EdgesInfos;

  startTimer("Building Graph...");
  // Build GO graph
  readNodes(graph, graphAttr, NodeInfos);
  readEdges(graph, EdgesInfos, graphAttr);
  stopTimer("Finished building graph.");

  if (graph.numberOfNodes() > 1) {
    _threads.push_back(
        thread([&graph, &graphAttr, &NodeInfos, &EdgesInfos, this]() {
          startTimer("Running GO Layout..");
          fmmmLayout(graphAttr);
          // hierarchyLayout(graphAttr);
          // PlanarStraightLayoutAlg(graphAttr);
          // return writeJSON(graph, graphAttr, NodeInfos, EdgesInfos,
          //_path.parent_path() / path("graph.json"));
          // stopTimer("Finished Running GO Layout.");
        }));
  }

  for (thread &t : _threads) {
    t.join();
  }

  return writeJSON(graph, graphAttr, NodeInfos, EdgesInfos);
}

void GraphProcessor::readNodes(Graph &G, GraphAttributes &GA,
                               NodeInfos &nodeInfos) {
  const Value &nodes = _document["nodes"];
  assert(nodes.IsArray());
  for (SizeType i = 0; i < nodes.Size(); i++) {
    const Value &data = nodes[i].GetObject()["data"];

    node elm = G.newNode();
    GA.idNode(elm) = i;
    std::map<std::string, std::variant<std::string, std::vector<std::string>>>
        properties;
    for (auto it = data.MemberBegin(); it != data.MemberEnd(); ++it) {
      if (it->value.IsString()) {
        properties[it->name.GetString()] = it->value.GetString();
      } else if (it->value.IsArray()) {
        std::vector<std::string> arrayValues;
        for (const auto &val : it->value.GetArray()) {
          arrayValues.push_back(val.GetString());
        }
        properties[it->name.GetString()] = arrayValues;
      }
    }
    nodeInfos.emplace_back(properties);
    GA.label(elm) = std::get<std::string>(properties["id"]);
    GA.width(elm) = 300;
    GA.height(elm) = 40;
  }
}

void GraphProcessor::readEdges(Graph &G, EdgeInfos &edgeInfos,
                               GraphAttributes &GA) {
  const Value &edges = _document["edges"];
  assert(edges.IsArray());
  std::string sourceId, targetId, edgeId;
  node source, target;
  for (SizeType i = 0; i < edges.Size(); i++) {
    const Value &data = edges[i].GetObject()["data"];
    sourceId = data["source"].GetString();
    targetId = data["target"].GetString();
    source = G.chooseNode(
        [&GA, &sourceId](node n) { return GA.label(n) == sourceId; }, true);
    target = G.chooseNode(
        [&GA, &targetId](node n) { return GA.label(n) == targetId; }, true);
    if (source && target) {
      G.newEdge(source, target);
      std::map<std::string, std::variant<std::string, std::vector<std::string>>>
          properties;
      for (auto it = data.MemberBegin(); it != data.MemberEnd(); ++it) {
        if (it->value.IsString()) {
          properties[it->name.GetString()] = it->value.GetString();
        } else if (it->value.IsArray()) {
          std::vector<std::string> arrayValues;
          for (const auto &val : it->value.GetArray()) {
            arrayValues.push_back(val.GetString());
          }
          properties[it->name.GetString()] = arrayValues;
        }
      }
      boost::uuids::uuid uuid = boost::uuids::random_generator()();
      properties["id"] = boost::uuids::to_string(uuid);
      edgeInfos.emplace_back(properties);
    }
  }
}

bool GraphProcessor::parseJSON() {
  _document.Parse(_jsonStr.c_str());
  return !_document.HasParseError();
}

string GraphProcessor::writeJSON(const Graph &graph, const GraphAttributes &GA,
                                 NodeInfos &nodeInfos, EdgeInfos &edgeInfos) {

  Document writeDoc;
  writeDoc.SetObject();
  Value elms(kObjectType);
  Value nodes(kArrayType);
  Value edges(kArrayType);
  int i = 0;
  for (const node &n : graph.nodes) {
    NodeInfo &info = nodeInfos[i];
    Value obj(kObjectType);
    info.serialize(writeDoc, obj, GA.x(n), GA.y(n));
    nodes.PushBack(obj, writeDoc.GetAllocator());
    i++;
  }
  elms.AddMember("nodes", nodes, writeDoc.GetAllocator());

  i = 0;
  for (const edge &e : graph.edges) {
    EdgeInfo &info = edgeInfos[i];
    Value obj(kObjectType);
    info.serialize(writeDoc, obj);
    edges.PushBack(obj, writeDoc.GetAllocator());
    i++;
  }
  elms.AddMember("edges", edges, writeDoc.GetAllocator());
  writeDoc.AddMember("elements", elms, writeDoc.GetAllocator());

  // FILE *fp = fopen(p.c_str(), "w");
  // char writeBuf[65536];
  // FileWriteStream ws(fp, writeBuf, sizeof(writeBuf));
  // Writer<FileWriteStream> writer(ws);
  // writeDoc.Accept(writer);
  // fclose(fp);
  StringBuffer buffer;
  Writer<StringBuffer> writer(buffer);
  writeDoc.Accept(writer);
  return buffer.GetString();
}

void GraphProcessor::startTimer(const string &msg) {
  _timer.start();
  cout << msg << endl;
}

void GraphProcessor::stopTimer(const string &msg) {
  cout << msg << " Took " << _timer.elapsed() << " seconds" << endl;
  _timer.reset();
}

} // namespace annotation_graph
