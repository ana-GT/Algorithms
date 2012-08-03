/**
 * @file MaxSubarray.cpp
 * @author A. Huaman
 */

#include "MaxSubarray.h"
#include <climits>
#include <math.h>
#include <stdio.h>

/**
 * @function FindMaxCrossing_Subarray
 */
void FindMaxCrossing_Subarray( std::vector<int> _A,
			       int _low,
			       int _mid,
			       int _high,
			       int &_max_left,
			       int &_max_right,
			       int &_max_sum ) {
  
  int left_sum; int right_sum;
  int max_left; int max_right;
  int sum;
  
  left_sum = INT_MIN;
  sum = 0;

  for( int i = _mid; i >= _low; --i ) {
    sum = sum + _A[i];
    if( sum > left_sum ) {
      left_sum = sum;
      max_left = i;
    }
  }

  right_sum = INT_MIN;
  sum = 0;

  for( int j = _mid + 1; j <= _high; ++j ) {
    sum = sum + _A[j];
    if( sum > right_sum ) {
      right_sum = sum;
      max_right = j;
    }
  }

  // Return
  _max_left = max_left;
  _max_right = max_right;
  _max_sum = left_sum + right_sum;
}

/**
 * @function FindMax_Subarray
 */
void FindMax_Subarray( std::vector<int> _A,
		       int _low,
		       int _high,
		       int &_max_low,
		       int &_max_high,
		       int &_max_sum ) {

  int mid;
  int left_low; int left_high; int left_sum;
  int right_low; int right_high; int right_sum;
  int cross_low; int cross_high; int cross_sum;

  // Base case: Only one element
  if( _high == _low ) {
    _max_low = _low;
    _max_high = _high;
    _max_sum = _A[_low];
  }

  // Divide and conquer
  else {
    mid = (int) floor( ( _low + _high ) / 2.0 );

    FindMax_Subarray( _A, _low, mid, left_low, left_high, left_sum );
    FindMax_Subarray( _A, mid+1, _high, right_low, right_high, right_sum );
    FindMaxCrossing_Subarray( _A, _low, mid, _high, cross_low, cross_high, cross_sum );     

    if( left_sum >= right_sum && left_sum >= cross_sum ) {
      _max_low = left_low;
      _max_high = left_high;
      _max_sum = left_sum;
    }
    else if( right_sum >= left_sum && right_sum >= cross_sum ) {
      _max_low = right_low;
      _max_high = right_high;
      _max_sum = right_sum;
    }
    else {
      _max_low = cross_low;
      _max_high = cross_high;
      _max_sum = cross_sum;    
    }
  } 

}
