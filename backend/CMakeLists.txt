cmake_minimum_required(VERSION 3.16)

project(SeeSeeStar LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(SeeSeeStar SHARED

  graph.cpp
  graph.h
  node.h
  node.cpp
  edge.h edge.cpp
  api.h api.cpp

)

target_compile_definitions(SeeSeeStar PRIVATE SEESEESTAR_LIBRARY)
