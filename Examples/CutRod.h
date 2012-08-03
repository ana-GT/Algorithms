/**
 * @file CutRod.h
 * @date 2012-07-11
 */

#include <vector>

int CutRod( std::vector<int> p,
	    int n );

/** Dynamic Programming Top-Down */
int MemoizedCutRod( std::vector<int> p,
		    int n );
int MemoizedCutRod_Aux( std::vector<int> p,
			int n,
			std::vector<int> r );

/** Dynamic Programming Bottom-Up */
int BottomUpCutRod( std::vector<int> p,
		    int n );
