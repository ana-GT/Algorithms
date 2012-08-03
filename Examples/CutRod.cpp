/**
 * @file CutRod.cpp
 */
#include "CutRod.h"
#include <climits>
#include <algorithm>

/**
 * @function CutRod
 */
int CutRod( std::vector<int> p,
	    int n ) {
  
  if( n == 0 ) {
    return 0;
  }

  int q;
  q = INT_MIN;

  for( int i = 1; i <= n;i++ ) {
    q = std::max( q, p[i] + CutRod(p, n-i) );
  }

  return q;
}

/**
 * @function MemoizedCutRod
 */
int MemoizedCutRod( std::vector<int> p,
		    int n ) {

  std::vector<int> r( n+1, INT_MIN );
  return MemoizedCutRod_Aux( p, n, r );
}

/**
 * @function MemoizedCutRod_Aux
 */
int MemoizedCutRod_Aux( std::vector<int> p,
			int n,
			std::vector<int> r ) {

  int q;

  if( r[n] >= 0 ) {
    return r[n];
  }

  if( n == 0 ) {
    q = 0;
  }
  else {
    q = INT_MIN;
    for( size_t i = 1; i <=n; ++i ) {
      q = std::max( q, p[i] + MemoizedCutRod_Aux(p, n-i, r) );
    }
    r[n] = q;
  }

  return q;
}

/**
 * @function
 */
int BottomUpCutRod( std::vector<int> p,
		    int n ) {

  std::vector<int> r(n+1);
  int q;

  r[0] = 0;

  for( size_t j = 1; j <=n; ++j ) {
    q = INT_MIN;
    for( size_t i = 1; i <=j; ++i ) {
      q = std::max( q, p[i] + r[j-i] );
    }
    r[j] = q;
  }

  return r[n];
}
