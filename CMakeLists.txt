cmake_minimum_required(VERSION 3.5.0)
project(alure-c-interface VERSION 1.0.1 DESCRIPTION "Alure C Interface for easier interioperability between programming languages")
add_library(alure-c-interface SHARED deviceManager.cpp device.cpp wrapString.cpp wrapStringVector.cpp)

set_target_properties(alure-c-interface PROPERTIES VERSION ${PROJECT_VERSION})

option(ALURE_BUILD_EXAMPLES OFF)
option(ALURE_BUILD_STATIC OFF)

add_subdirectory(alure)
add_dependencies(alure-c-interface alure2)
target_link_libraries(alure-c-interface alure2)
