/**
 * @file test.cpp
 */
#include "Vertex.h"
#include "Graph.h"
#include "BFS.h"
#include "Ford.h"

/**
 * @function main
 */
int main( int argc, char* argv[] ) {
  
  int n = 6;
  Graph<Vertex> g(n);
  for( int i = 0; i < n; ++i ) {
    Vertex* v = new Vertex(i);
    g.setVertex( i , v );
  }

  Vertex* u; 
  u = g.getVertex(0);
  u->addAdjV( g.getVertex(1), 16, 0 );
  u->addAdjV( g.getVertex(2), 13, 0 );

  u = g.getVertex(1);
  u->addAdjV( g.getVertex(3), 12, 0 );

  u = g.getVertex(2);
  u->addAdjV( g.getVertex(1), 4, 0 );
  u->addAdjV( g.getVertex(4), 14, 0 );

  u = g.getVertex(3);
  u->addAdjV( g.getVertex(2), 9, 0 );
  u->addAdjV( g.getVertex(5), 20, 0 );

  u = g.getVertex(4);
  u->addAdjV( g.getVertex(3), 7, 0 );
  u->addAdjV( g.getVertex(5), 4, 0 );
 
  Ford f;
  int outflow =  f.maxFlow( &g, 0, 5 );
  
  /*
  int n = 4;
  Graph<Vertex> g(n);

  for( int i = 0; i < n; ++i ) {
    Vertex* v = new Vertex(i);
    g.setVertex( i , v );
  }

  Vertex* u; 
  u = g.getVertex(0);
  u->addAdjV( g.getVertex(1), 1000000, 0 );
  u->addAdjV( g.getVertex(3), 1000000, 0 );

  u = g.getVertex(1);
  u->addAdjV( g.getVertex(2), 1000000, 0 );
  u->addAdjV( g.getVertex(3), 1, 0 );

  //u = g.getVertex(2);

  u = g.getVertex(3);
  u->addAdjV( g.getVertex(2), 1000000, 0 );
 
  Ford f;
  int outflow =  f.maxFlow( &g, 0, 2 );
  */
  printf("\n * Graph Outflow: %d \n", outflow );
  f.printFlow( &g );
  
}
