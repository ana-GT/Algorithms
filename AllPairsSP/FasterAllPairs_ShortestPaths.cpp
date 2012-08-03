/**
 * @function FasterAllPairs_ShortestPaths.h
 */

#include <algorithm>
#include <string.h>
#include "FasterAllPairs_ShortestPaths.h"


/**
 * @function FasterAllPairs_ShortestPaths
 * @brief Constructor
 */
FasterAllPairs_ShortestPaths::FasterAllPairs_ShortestPaths() {

  // Init to NULL or horrible things will happen (Yes, you are right, SEG FAULT!)
  Lm = NULL;
  L2m = NULL;
}

/**
 * @function ~FasterAllPairs_ShortestPaths
 * @brief Destructor
 */
FasterAllPairs_ShortestPaths::~FasterAllPairs_ShortestPaths() {

  if( Lm != NULL ) {
    delete [] Lm;
  }
  if( L2m != NULL ) {
    delete [] L2m;
  }
}


/**
 * @function search
 */
int* FasterAllPairs_ShortestPaths::search( Graph* _g ) {

  numV = _g->getNumV();
  stride_x = numV;
  
  // Initialize Lm = W
  Lm = new int[numV*numV];
  memcpy( Lm, _g->getW(), numV*numV*sizeof(int) );

  // Go find paths up to (numV) vertices
  int m = 1;  

  while( m < numV ) {
    L2m = new int[numV*numV];
    L2m = extend_ShortestPaths( Lm, Lm );

    m = 2*m;
    //    delete Lm;
    Lm = new int[numV*numV];
    memcpy( Lm, L2m, numV*numV*sizeof(int) );
    //delete L2m;
  } 

  return Lm;
}

/**
 * @function extend_ShortestPaths
 */
int* FasterAllPairs_ShortestPaths::extend_ShortestPaths( int* _L, int *_W ) {

  int* L = new int[numV*numV];

  for( int i = 0; i < numV; ++i ) {
    for( int j = 0; j < numV; ++j ) {

      int Lij_temp;
      Lij_temp = INF;

      for( int k = 0; k < numV; ++k ) {
	int l = _L[ ref(i,k) ];
	int w = _W[ ref(k,j) ];
	if( l == INF || w == INF ) {
	  continue;
	}
	else {
	  Lij_temp = std::min( Lij_temp, l + w );
	}
      }
      L[ ref(i,j) ] = Lij_temp;
    }
  }

  return L;
}

/**
 * @function print_Matrix
 */
void FasterAllPairs_ShortestPaths::print_Matrix( int* _M, int _m, int _n ) {

  for( int i = 0; i < _m; ++i ) {
    for( int j =0; j < _n; ++j ) {
      int m = _M[ i*_n + j ];
      if( m == INF ) {
	printf( "  INF " );
      }
      else {
	printf( "    %d ", m );
      }
    }
    printf("\n");
  }
}
