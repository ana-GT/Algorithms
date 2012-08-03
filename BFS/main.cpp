/**
 * @file main.cpp
 */

#include <stdio.h>
#include <iostream>

#include "Graph.h"
#include "BFS.h"

/**
 * @function main 
 */
int main( int argc, char* argv[] ) {

  Graph g (100,100,100);
  BFS( &g, 0 );
  printf("Done \n");
  return 0;
}
