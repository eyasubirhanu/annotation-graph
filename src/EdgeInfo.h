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

#include "rapidjson/document.h"
#include <map>
#include <string>
#include <variant>
#include <vector>

using namespace rapidjson;

namespace annotation_graph {
struct EdgeInfo {
  EdgeInfo(const std::map<std::string,
                          std::variant<std::string, std::vector<std::string>>>
               &properties)
      : properties(properties) {}

  std::map<std::string, std::variant<std::string, std::vector<std::string>>>
      properties;

  void serialize(Document &doc, Value &obj) {
    Value data(kObjectType);
    for (const auto &[key, value] : properties) {
      if (std::holds_alternative<std::string>(value)) {
        data.AddMember(Value().SetString(key.c_str(), doc.GetAllocator()),
                       Value().SetString(std::get<std::string>(value).c_str(),
                                         doc.GetAllocator()),
                       doc.GetAllocator());
      } else if (std::holds_alternative<std::vector<std::string>>(value)) {
        Value arr(kArrayType);
        for (const auto &str : std::get<std::vector<std::string>>(value)) {
          arr.PushBack(Value().SetString(str.c_str(), doc.GetAllocator()),
                       doc.GetAllocator());
        }
        data.AddMember(Value().SetString(key.c_str(), doc.GetAllocator()), arr,
                       doc.GetAllocator());
      }
    }
    obj.AddMember("data", data, doc.GetAllocator());
    // obj.AddMember("group", "edges", doc.GetAllocator());
  }
};
} // namespace annotation_graph
