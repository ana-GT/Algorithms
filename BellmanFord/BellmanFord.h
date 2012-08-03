/**
 * @file BellmanFord.h
 */

#ifndef _BELLMAN_FORD_H_
#define _BELLMAN_FORD_H_

#include "Graph.h"

/**
 * @class BellmanFord
 */
class BellmanFord{

 public:
  BellmanFord( Graph* _g, int _s );
  ~BellmanFord();
  bool search();
  bool print_Path( int _t );

 private:
  void initialize_SingleSource( int _s_key ); 
  bool relax( Vertex* _u, Vertex* _v, int _w );

  Graph* G;
  int s_key; /**< root vertex */
  int numV;  /**< Num vertices */
};

#endif /** _BELLMAN_FORD_H_ */

