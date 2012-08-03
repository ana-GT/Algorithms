/**
 * @file Graph.h
 * @brief
 */
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <cstddef> /** NULL */
#include <climits>

#define INF INT_MAX

/**
 * @class Graph
 */
class Graph {

 public:
  Graph( int _n );
  ~Graph();
  bool addEdge( int _u, int _v, int _weight = 1 );
  bool isEdge( int _u, int _v );
  inline int ref( int _u, int _v );
  inline int getNumV();
  inline bool isValidEdge( int _u, int _v );
  inline int* getW();

 
 private:
  int numV;
  int* W;
  int stride_x;

};

/**
 * @function ref
 * @brief Reference to multidimensional data in 1D array
 */
inline int Graph::ref( int _u, int _v ) {
  return _u*stride_x + _v;
}

/**
 * @function getNumV
 */
inline int Graph::getNumV() {
  return numV;
}

/**
 * @function isValidEdge
 */
inline bool Graph::isValidEdge( int _u, int _v ) {
  if( _u < 0 || _u >= numV || _v < 0 || _v >= numV ) {
    return false;
  }
  else {
    return true;
  }
}

/**
 * @function getW
 */
inline int* Graph::getW() {
  return W;
}

#endif /** _GRAPH_H_ */

