cmake_minimum_required(VERSION 3.14)
project (ExampleNodes VERSION 0.0.1)

find_package(geoflow REQUIRED)

set(GF_PLUGIN_NAME ${PROJECT_NAME})
set(GF_PLUGIN_TARGET_NAME "gfp_example")
set(GF_PLUGIN_REGISTER ${PROJECT_SOURCE_DIR}/register.hpp)
configure_file(${GF_PLUGIN_FILE} ${PROJECT_BINARY_DIR}/gf_plugin.cpp)

add_library(${GF_PLUGIN_TARGET_NAME} MODULE
  ${PROJECT_BINARY_DIR}/gf_plugin.cpp
)
target_link_libraries(${GF_PLUGIN_TARGET_NAME} geoflow-core)

set_target_properties(
  ${GF_PLUGIN_TARGET_NAME} PROPERTIES 
  CXX_STANDARD 17 
  PREFIX ""
)

install(TARGETS ${GF_PLUGIN_TARGET_NAME} DESTINATION ${geoflow_PLUGIN_FOLDER})