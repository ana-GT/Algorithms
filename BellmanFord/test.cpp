/**
 * @file test.cpp
 */

#include "Graph.h"
#include "BellmanFord.h"
#include <stdio.h>

/**
 * @function main
 */
int main ( int argc, char* argv[] ) {
  
  printf("Start \n");
  int n = 5000;
  Graph g( n );

  for( int i = 0; i < n; ++i ) {
    Vertex* v = new Vertex( i );
    g.set_Vertex( v, i );
  }

  g.add_Edge( 0, 1, 10 );
  g.add_Edge( 0, 3, 5 );
  g.add_Edge( 1, 2, 1 );
  g.add_Edge( 1, 3, 2 );
  g.add_Edge( 2, 4, 4 );

  g.add_Edge( 3, 1, 3 );
  g.add_Edge( 3, 2, 9 );
  g.add_Edge( 3, 4, 2 );
  g.add_Edge( 4, 2, 6 );
  g.add_Edge( 4, 0, 7 );
 
  BellmanFord b( &g, 0 );
  bool check = b.search();
  if( check == true ) {
    printf("If check is okay \n");
    b.print_Path( 1 );
    b.print_Path( 2 );
    b.print_Path( 3 );
    b.print_Path( 4 );
  }
  else {
    printf("Check is not okay \n");
  }
  printf("End \n");
}
