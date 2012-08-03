/**
 * @file MaxSubarray.h
 * @author A. Huaman
 * @brief Algorithms Ch 4 - example 1 - MaxSubarray problem
 */
#include <vector>


void FindMaxCrossing_Subarray( std::vector<int> _A,
			       int _low,
			       int _mid,
			       int _high,
			       int &_max_left,
			       int &_max_right,
			       int &_max_sum );

void FindMax_Subarray( std::vector<int> _A,
		       int _low,
		       int _high,
		       int &_max_low,
		       int &_max_high,
		       int &_max_sum );
