/**
 * @file Graph.h
 * @author A. Huaman
 * @date 2012-07-31
 */
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <vector>

#include "Vertex.h"

/**
 * @class Graph
 */
template <class Tv>
class Graph {

 public:
  Graph( int _N );   /**< Constructor */
  ~Graph();  /**< Destructor */ 

  void setVertex( int _i, Tv* _v );
  Tv* getVertex( int _i );
  Tv** getVertexPointer( int _i );
  inline int getNumV();

 private:
  Tv** V; /**< Vertices */ 
  int numV; /**< Vertices number */

};

/**
 * @function Graph
 * @brief Constructor
 */
template<class Tv>
  Graph<Tv>::Graph( int _N ) {

  numV = _N;
  V = new Tv*[numV];
}


/**
 * @function ~Graph
 * @brief Destructor
 */
template<class Tv>
  Graph<Tv>::~Graph() {
 
}

/**
 * @function setVertex
 */
template<class Tv>
  void Graph<Tv>::setVertex( int _i, Tv* _v ) {
  V[_i] = _v;
}


/**
 * @function getVertice
 */
template<class Tv>
  Tv* Graph<Tv>::getVertex( int _i ) {

  return V[_i];
}

/**
 * @function getVertice
 */
template<class Tv>
  Tv** Graph<Tv>::getVertexPointer( int _i ) {

  return &V[_i];
}


/**
 * @function getNumV
 */
template<class Tv>
inline int Graph<Tv>::getNumV() {
  return numV;
}

#endif /** _GRAPH_H_ */
