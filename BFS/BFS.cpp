/**
 * @file BFS.cpp
 * @brief Breadth-first Search implementation
 * @author A. Huaman Q.
 */

#include <stdio.h>
#include "BFS.h"
#include <time.h>

/**
 * @function BFS
 */
void BFS( Graph *_g, int _startIndex ) {
  
  // Initialize all vertices
  int n = _g->getNumV();

  time_t ts;
  time_t tf;
  double diff;

  ts = clock();
  Vertex *V = _g->getV(0);
  for( size_t i = 0; i < n; ++i ) {

    V->color = WHITE;
    V->d = INF;
    V->parent = NIL;
    V++;
  }
  tf = clock();
  diff = (double)(tf-ts)/((double)CLOCKS_PER_SEC);
  printf("Time pointer: %f \n", diff);

  // Initialize start vertex
  Vertex *Vs = _g->getV( _startIndex );
  Vs->color = GRAY;
  Vs->d = 0;
  Vs->parent = NIL;
  
  // Initialize Q to be an empty Queue
  Queue Q;
  Q.Enqueue( _startIndex );
  
  // While loop
  Vertex* u;
  Vertex* v;

  while( !Q->isEmpty() ) {

    int u_key = Q.Dequeue();
    u = _g->getV(u_key);

    for( size_t i = 0; i < _g->AdjList ) {
      if( v->color == WHITE ) {
	v->color = GRAY;
	v->d = u->d + 1;
	v->parent = u;
	Q.Enqueue(v);
      }
    }
    u->color = BLACK;
  }
}
