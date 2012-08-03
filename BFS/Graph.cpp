/**
 * @file Graph.cpp
 */

#include <stdio.h>
#include "Graph.h"

Vertex::Vertex( ) {
  color = GRAY;
}

/**
 * @function Graph
 * @brief Constructor
 */
Graph::Graph() {
  init();
}

/**
 * @function Graph
 * @brief Constructor
 */
Graph::Graph( int _dim_x, int _dim_y, int _dim_z ) {
  init();
  dimX = _dim_x;
  dimY = _dim_y;
  dimZ = _dim_z;
  numV = dimX*dimY*dimZ;

  // Initialize V
  V = new Vertex[numV]; 
}

/**
 * @function Graph
 * @brief Destructor
 */
Graph::~Graph() {
  
  if( V != NULL ) {
    delete V;
  }
}

/**
 * @function Reset
 */
void Graph::init() {
  V = NULL;
}

/**
 * @function getV
 */
Vertex* Graph::getV( int _index ) {
  return &V[_index];
}
