# BFS Project

cmake_minimum_required( VERSION 2.8 )

project( BFS )

include_directories( /usr/local/include/eigen3 )

set( SRC_FILES Graph.cpp BFS.cpp )
set( HDR_FILES Graph.h BFS.h )

add_executable( BFS main.cpp ${SRC_FILES} ${HDR_FILES} )
		
