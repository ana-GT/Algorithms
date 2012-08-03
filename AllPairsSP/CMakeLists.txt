# ALL_PAIRS

cmake_minimum_required( VERSION 2.8 )
set (CMAKE_CXX_COMPILER "g++-4.4" )

project( ALL_PAIRS )

set( SRC_FILES Graph.cpp FasterAllPairs_ShortestPaths.cpp )
set( HDR_FILES Graph.h FasterAllPairs_ShortestPaths.h )

add_executable( test test.cpp ${SRC_FILES} ${HDR_FILES} )
