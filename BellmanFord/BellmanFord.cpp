/**
 * @file BellmanFord.cpp
 * @author A. Huaman Quispe
 * @date 2012-08-03
 */

#include <stdio.h>
#include "Vertex.h"
#include "BellmanFord.h"

/**
 * @function BellmanFord
 * @brief Constructor
 */
BellmanFord::BellmanFord( Graph* _g, int _s ) {
  G = _g;
  numV = G->get_NumV();
  s_key = _s;
}

/**
 * @function ~BellmanFord
 * @brief Destructor
 */
BellmanFord::~BellmanFord() {

}

/**
 * @function search
 */ 
bool BellmanFord::search() {

  Vertex* u;
  std::vector<Vertex*> v;
  std::vector<int> w;
  Vertex** up;

  printf("Start search \n");
  // Initialize single source
  initialize_SingleSource( s_key );

  
  // For (numV - 1) times
  for( int i = 0; i < numV - 1; ++i ) {
    // For all edges
    up = G->get_VertexPointer( 0 );

    for( int j = 0; j < numV; ++j ) {
      
      v = (*up)->get_adjV();
      w = (*up)->get_w();
      for( int k = 0; k < v.size(); ++k ) {
	relax( (*up), v[k], w[k] );
      }
      up++;
    }
  }
  
  /*
  // For (numV - 1) times
  for( int i = 0; i < numV - 1; ++i ) {
    // For all edges
    for( int j = 0; j < numV; ++j ) {
      u = G->get_Vertex(j);
      v = u->get_adjV();
      w = u->get_w();
      for( int k = 0; k < v.size(); ++k ) {
	relax( u, v[k], w[k] );
      }
    }
  }
  */

  printf("Start search for cycles \n");
  // Check for cycles
  // For all edges
  for( int j = 0; j < numV; ++j ) {
    u = G->get_Vertex( j );
    v = u->get_adjV();
    w = u->get_w();
    for( int k = 0; k < v.size(); ++k ) {
      if( v[k]->get_d() > u->get_d() + w[k] ) {
	return false;
      } 
    }
  }
  
  return true;
}

/**
 * @function initialize_SingleSource
 */
void BellmanFord::initialize_SingleSource( int _s_key ) {

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
bool BellmanFord::relax( Vertex* _u, Vertex* _v, int _w ) {

  int uw = _u->get_d() + _w;

  if( _v->get_d() > uw ) {
    _v->set_d( uw );
    _v->set_parent( _u->get_key() );
  }
}

/**
 * @function print_Path
 */
bool BellmanFord::print_Path( int _t ) {
  
  Vertex* v;
  int parent;
  std::vector<int> path;
  std::vector<int> path_backwards;

  v = G->get_Vertex(_t);
  parent = v->get_parent();


  if( parent == NIL ) {
    printf(" BellmanFord: No path to start vertex  - Exiting \n");
    return false;
  } 

  if( ( G->get_Vertex(s_key) )->get_parent() != NIL ) {
    printf(" BellmanFord: No source root, WTH? - Exiting \n");
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
