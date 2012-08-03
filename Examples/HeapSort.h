/**
 * @file HeapSort.h
 * @author A. Huaman
 * @date 2012-07-11
 */

#include <vector>

void MaxHeapify( std::vector<int> &_A,
		 int _i );
void BuildMaxHeap( std::vector<int> &_A );

inline int Left( int _i );
inline int Right( int _i );
inline int Parent( int _i );

