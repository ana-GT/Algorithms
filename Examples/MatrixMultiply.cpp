/**
 * @file MatrixMultiply.cpp
 * @author A. Huaman
 */
#include <Eigen/Core>
#include <stdio.h>

#include "MatrixMultiply.h"

/**
 * @function MatrixMultiply
 */
Eigen::MatrixXd MatrixMultiply( Eigen::MatrixXd _A,
				Eigen::MatrixXd _B ) {

  Eigen::MatrixXd C( _A.rows(), _B.cols() );
  if( _A.cols() != _B.rows() ) {
    printf("--(!) Incompatible dimensions! \n");
  }

  else {
    for( size_t i = 0; i < _A.rows(); ++i ) {
      for( size_t j =0; j < _B.cols(); ++j ) {
	C(i,j) = 0;
	for( size_t k=0; k < _A.cols(); ++k ) {
	  C(i,j) += _A(i,k)*_B(k,j);
	}
      }
    }
  }

  return C;
}
