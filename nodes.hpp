// This file is part of Geoflow
// Copyright (C) 2018-2019  Ravi Peters, 3D geoinformation TU Delft

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <geoflow/geoflow.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace geoflow;

class AdderNode:public Node {
  public:
  using Node::Node;

  void init() {
    add_input("in1", typeid(int));
    add_input("in2", typeid(int));
    add_output("result", typeid(int));
  }

  std::string info() {
    std::string s;
    if (output("result").has_data())
      s = std::to_string(output("result").get<int>());
    return s;
  }

  void process() {
    std::cout << "begin AddderNode::process()" << "\n";
    auto in1 = input("in1").get<int>();
    auto in2 = input("in2").get<int>();
    std::this_thread::sleep_for(std::chrono::microseconds(200));
    output("result").set(int(in1+in2));
    std::cout << "end AddderNode::process()" << "\n";
  }
};

class NumberNode:public Node {
  int value=21;
  public:
  using Node::Node;

  void init() {
    add_output("result", typeid(int));
    add_param("number_value", ParamInt(value));
  }
  
  void process() {
    std::cout << "begin NumberNode::process()" << "\n";
    output("result").set(int(value));
    std::cout << "end NumberNode::process()" << "\n";
  }
};

void register_nodes(NodeRegister& node_register) {
  node_register.register_node<AdderNode>("Adder");
  node_register.register_node<NumberNode>("Number");
}

NodeRegisterHandle create_register() {
  auto R = NodeRegister::create(GF_PLUGIN_NAME);
  register_nodes(*R);
  return R;
}