

// Main Code for testing CutRod
  std::vector<int> p(11);
  p[0] = 0;
  p[1] = 1;
  p[2] = 5;
  p[3] = 8;
  p[4] = 9;
  p[5] = 10;
  p[6] = 17;
  p[7] = 17;
  p[8] = 20;
  p[9] = 24;
  p[10] = 30;  

  for( size_t i = 0; i <= 10; ++i ) {
    int q = CutRod( p, i );
    printf( "Revenue for n = %d is %d \n", i, q );
  }

  for( size_t i = 0; i <= 10; ++i ) {
    int q = MemoizedCutRod( p, i );
    printf( "[Memoized] Revenue for n = %d is %d \n", i, q );
  }

  for( size_t i = 0; i <= 10; ++i ) {
    int q = BottomUpCutRod( p, i );
    printf( "[BottomUp] Revenue for n = %d is %d \n", i, q );
  }
