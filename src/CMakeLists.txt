cmake_minimum_required(VERSION 3.23)

project(agent)

file(GLOB MODELING_SRCS modeling/*.cpp)
add_library(modeling ${MODELING_SRCS})

file(GLOB DECISION_MAKING_SRCS decision_making/*.cpp)
add_library(decision_making ${DECISION_MAKING_SRCS})

file(GLOB PARSER_SRCS parser/*.cpp)
add_library(parser ${PARSER_SRCS})

add_executable(agent main.cpp)
target_link_libraries(agent modeling decision_making parser)

target_include_directories(modeling PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(decision_making PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})