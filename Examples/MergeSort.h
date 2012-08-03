/**
 * @file MergeSort.h
 * @author A. Huaman
 * @date 2012-07-11
 */

#include <vector>
#include <iostream>
#include <limits>


/**
 * @function MergeSort
 */
template<class T>
void MergeSort( std::vector<T> &_A,
		int p,
		int r ) {
  int q;

  if( p < r) {
    q = (p+r) / 2;
    MergeSort( _A, p, q );
    MergeSort( _A, q+1, r );
    Merge( _A, p, q, r );
  }
}

/**
 * @function Merge
 */
template<class T>
void Merge( std::vector<T> &_A,
	    int p,
	    int q, 
	    int r ) {
  
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<T> L(n1+1);
  std::vector<T> R(n2+1);

  int i;
  int j;

  for(  i = 0; i < n1; ++i ) {
    L[i] = _A[p+i];
  }
  for( j = 0; j < n2; ++j ) {
    R[j] = _A[q+1+j];
  }
  L[n1] = std::numeric_limits<T>::max();
  R[n2] = std::numeric_limits<T>::max(); 

  // Merge them together
  i = 0; j = 0;
  for( size_t k = p; k <= r; k++ ) {

    
    if( L[i] <= R[j] ) {
      _A[k] = L[i];
      i++;
    }
    else {
      _A[k] = R[j];
      j++;
    }
  }
}
