cmake_minimum_required(VERSION 3.14)
project (ExampleNodes VERSION 0.0.1)

add_definitions(-DGF_PLUGIN_NAME=\"${PROJECT_NAME}\")

find_package(geoflow REQUIRED)

add_library(gfp_example MODULE
  plugin.cpp
)
target_link_libraries(gfp_example geoflow-core)

set_target_properties(
  gfp_example
  PROPERTIES CXX_STANDARD 17
)

install(TARGETS gfp_example DESTINATION ${geoflow_PLUGIN_FOLDER})