/**
Created by Abdulrahman Semrie<hsamireh@gmail.com> on 10/2/20
Copyright © 2020 Abdulrahman Semrie
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

#ifndef ANNOTATION_GRAPH_GRAPHPROCESSOR_H
#define ANNOTATION_GRAPH_GRAPHPROCESSOR_H
#include "EdgeInfo.h"
#include "NodeInfo.h"
#include "Timer.h"
#include <boost/filesystem.hpp>
#include <ogdf/basic/Graph.h>
#include <ogdf/fileformats/GraphIO.h>
#include <rapidjson/document.h>
#include <thread>

using namespace ogdf;
using namespace rapidjson;
using namespace boost::filesystem;
using namespace std;

namespace annotation_graph {
// typedef function<bool(const Value&)> NodeFilter;

typedef vector<NodeInfo> NodeInfos;
typedef vector<EdgeInfo> EdgeInfos;
typedef vector<thread> Threads;

class GraphProcessor {
public:
  GraphProcessor(const string &jsonStr) : _jsonStr(jsonStr) {}

  string processGraph();

private:
  void readNodes(Graph &G, GraphAttributes &GA, NodeInfos &nodeInfos
                 /*const function<bool(const Value &)> &filterNodes*/);
  void readEdges(Graph &G, EdgeInfos &edgeInfos, GraphAttributes &GA);
  bool parseJSON();
  string writeJSON(const Graph &graph, const GraphAttributes &GA,
                   NodeInfos &nodeInfos, EdgeInfos &edgeInfo);
  void startTimer(const string &msg);
  void stopTimer(const string &msg);

  Document _document;
  string _jsonStr;
  Timer _timer;
  Threads _threads;
};
} // namespace annotation_graph

#endif // ANNOTATION_GRAPH_GRAPHPROCESSOR_H
