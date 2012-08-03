
#include <stdio.h>
#include "Graph.h"
#include "FasterAllPairs_ShortestPaths.h"


/**
 * @function main
 */
int main( int argc, char* argv[] ) {
  printf("Graph start \n");
  Graph g(1000);
  g.addEdge( 0, 1, 2 );
  g.addEdge( 1, 2, 3 );
  g.addEdge( 2, 4, 4 );
  g.addEdge( 3, 2, 5 );
  g.addEdge( 3, 4, 6 );

  FasterAllPairs_ShortestPaths f;
  int* m;
  m = f.search( &g );
  int nm = f.getNumV();
  printf("Graph end \n");
  //  f.print_Matrix( m, nm, nm );
 
}
