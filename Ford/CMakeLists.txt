# FORD Project

cmake_minimum_required( VERSION 2.8 )
set (CMAKE_CXX_COMPILER "g++-4.4" )

project( FORD )

include_directories( /usr/local/include/eigen3 )

set( SRC_FILES Vertex.cpp )
set( HDR_FILES  Vertex.h Graph.h BFS.h Queue.h Ford.h )

add_executable( test test.cpp ${SRC_FILES} ${HDR_FILES} )
