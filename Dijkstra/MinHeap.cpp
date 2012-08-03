/**
 * @file MinHeap.cpp 
 * @brief 
 * @author A. Huaman
 * @date 2012-08-03
 */
#include "MinHeap.h"
#include <stdio.h>

/**
 * @function MaxHeapify
 */
void MaxHeapify( std::vector<int> &_A,
	    int _i ) {
  
  int heapSize = _A.size();
  int largest;
  int temp;

  int l = Left(_i);
  int r = Right(_i);

  if( l < heapSize && _A[l] > _A[_i] ) {
    largest = l;
  }
  else {
    largest = _i;
  }
  if( r < heapSize && _A[r] > _A[largest] ) {
    largest = r;
  }

  if( largest != _i ) {

    // Exchange
    temp = _A[_i];
    _A[_i] = _A[largest];
    _A[largest] = temp;

    MaxHeapify( _A, largest );
  }  
}

/**
 * @function BuildMaxHeap
 */
void BuildMaxHeap( std::vector<int> &_A ) {

  int n = _A.size();
  int heapSize = _A.size();

  for( int i = Parent(n-1); i >= 0; i-- ) {
    printf("MaxHeapify for %d \n", i);
    MaxHeapify( _A, i );
  }
}

