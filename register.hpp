#include "nodes.hpp"

void register_nodes(geoflow::NodeRegister& node_register) {
  node_register.register_node<AdderNode>("Adder");
  node_register.register_node<NumberNode>("Number");
}