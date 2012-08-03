#include <iostream>
#include <stdio.h>
#include <vector>

/**
 * @function InsertionSort
 */
template<class T>
void InsertionSort( std::vector<T> &_array ) {
  T key;
  size_t i;
  
  for( size_t j = 1; j < _array.size(); ++j ) {
    key = _array[j];
    // Insert _array[j] into the sorted sequence A[1,..,j-1]
    i = j - 1;
    while( i >= 0 && _array[i] > key ) {
      printf("Change \n");
      _array[i+1] = _array[i];
      i = i - 1;
    }
    _array[i+1] = key;
  }
  
}
