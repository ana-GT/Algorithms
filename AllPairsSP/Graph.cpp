/**
 * @file Graph.cpp
 */

#include "Graph.h"

/**
 * @function Graph
 */
Graph::Graph( int _n ) {

  numV = _n;
  stride_x = _n;
  W = new int[numV*numV];

  // Initialize W default
  for( int i = 0; i < numV; ++i ) {
    for( int j = 0; j < numV; ++j ) {
      if( i == j ) {
	W[ ref(i,j) ] = 0;
      }
      else {
	W[ ref(i,j) ] = INF;
      }
    }
  }
 
}

/**
 * @function ~Graph
 */
Graph::~Graph() {
  if ( W != NULL ) {
    delete  W;
  }
}

/**
 * @function addEdge
 */
bool Graph::addEdge( int _u, int _v, int _weight ) {
  if( isValidEdge(_u, _v) ) {
    W[ref(_u,_v)] = _weight;
    return true;}
  else {
    return false;
  }
}

/**
 * @function isEdge
 */
bool Graph::isEdge( int _u, int _v ) {
  return true;
}


