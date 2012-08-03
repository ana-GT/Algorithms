/**
 * @file FasterAllPairs_ShortestPaths
 */


#ifndef _FASTER_ALL_PAIRS_H_
#define _FASTER_ALL_PAIRS_H_

#include <stdio.h>
#include "Graph.h"


/**
 * @class FasterAllPairs_ShortestPaths
 */
class FasterAllPairs_ShortestPaths {
  
 public:
  FasterAllPairs_ShortestPaths();
  ~FasterAllPairs_ShortestPaths();

  int* search( Graph* _g );
  int* extend_ShortestPaths( int* _L, int *_W );
  inline int getNumV();
  void print_Matrix( int* _M, int _m, int _n );

 private:

  inline int ref( int _u, int _v );
  int* Lm;
  int* L2m;
  int numV;
  int stride_x;
 
};

/**
 * @function ref
 */
inline int FasterAllPairs_ShortestPaths::ref( int _u, int _v ) {
  return _u*stride_x + _v;
}

/**
 * @function getNumV
 */
inline int FasterAllPairs_ShortestPaths::getNumV() {
  return numV;
}

#endif /** _FASTER_ALL_PAIRS_H_ */
