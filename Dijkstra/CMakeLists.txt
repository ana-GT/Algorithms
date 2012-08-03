# BELLMAN_FORD Project

cmake_minimum_required( VERSION 2.8 )
set( CMAKE_CXX_COMPILE "g++-4.4" )

project( BELLMAN_FORD )

set ( SRC_FILES Vertex.cpp Graph.cpp BellmanFord.cpp )
set ( HDR_FILES Vertex.h Graph.h BellmanFord.h )

add_executable( test test.cpp ${SRC_FILES} ${HDR_FILES} )
