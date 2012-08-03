/**
 * @file Dijkstra.cpp
 * @author A. Huaman Quispe
 * @date 2012-08-03
 */

#include <stdio.h>
#include "Vertex.h"
#include "Dijkstra.h"
#include "Queue.h"

/**
 * @function Dijkstra
 * @brief Constructor
 */
Dijkstra::Dijkstra( Graph* _g, int _s ) {
  G = _g;
  numV = G->get_NumV();
  s_key = _s;
}

/**
 * @function ~Dijkstra
 * @brief Destructor
 */
Dijkstra::~Dijkstra() {

}

/**
 * @function search
 */ 
bool Dijkstra::search() {

  Vertex* u;
  std::vector<Vertex*> v;
  std::vector<int> w;
  Vertex** up;

  // Initialize single source
  initialize_SingleSource( s_key );

  // Initialize Queue
  Queue<Vertex> Q;
  
  // Enqueue all vertices
  up = G->get_VertexPointer(0);
  for( int i = 0; i < numV; ++i ) {
    Q.Enqueue( *up );
    ++up;
  }

  // Loop
  while( Q.size() != 0 ) {

    u = Q.ExtractMin();
    std::vector<Vertex*> v = u->get_adjV();
    std::vector<int> w = u->get_adjV();

    for( int i = 0; i < adj.size(); ++i ) {
      relax( u, v[i], w[i] );
    }
  }
  
  return true;
}

/**
 * @function initialize_SingleSource
 */
void Dijkstra::initialize_SingleSource( int _s_key ) {

  Vertex* v;

  // Set all vertices
  for( int i = 0; i < numV; ++i ) {
    v = G->get_Vertex(i);
    v->set_d( INF );
    v->set_parent( NIL );
  }
  
  // Set root vertex
  v = G->get_Vertex( _s_key );
  v->set_d(0);
}

/**
 * @function relax
 */
bool Dijkstra::relax( Vertex* _u, Vertex* _v, int _w ) {

  int uw = _u->get_d() + _w;

  if( _v->get_d() > uw ) {
    _v->set_d( uw );
    _v->set_parent( _u->get_key() );
  }
}

/**
 * @function print_Path
 */
bool Dijkstra::print_Path( int _t ) {
  
  Vertex* v;
  int parent;
  std::vector<int> path;
  std::vector<int> path_backwards;

  v = G->get_Vertex(_t);
  parent = v->get_parent();


  if( parent == NIL ) {
    printf(" Dijkstra: No path to start vertex  - Exiting \n");
    return false;
  } 

  if( ( G->get_Vertex(s_key) )->get_parent() != NIL ) {
    printf(" Dijkstra: No source root, WTH? - Exiting \n");
    return false;
  }
  
  // last element
  path_backwards.push_back( v->get_key() );

  // iterate until source vertex
  while( parent != NIL ) {  
    v = G->get_Vertex( parent );
    path_backwards.push_back( v->get_key() );
    parent = v->get_parent();
  }

  int n = path_backwards.size();
  for( int i = 0; i < n; ++i ) {
    printf(" %d ->", path_backwards[n-1-i] );
  }
  printf("\n");

  return true;
}
