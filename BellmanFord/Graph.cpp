/**
 * @file Graph.cpp
 * @brief Implementation of Graph class
 */
#include "Graph.h"

/**
 * @function Graph
 * @brief Constructor
 */
Graph::Graph( int _N ) {
  numV = _N;
  V = new Vertex*[numV];

}

/**
 * @function ~Graph
 * @brief Destructor
 */
Graph::~Graph() {
  if( V != NULL ) {
    delete [] V;
  }
}

/**
 * @function set_Vertex
 */
int Graph::set_Vertex( Vertex* _v, int _key ) {
  V[_key] = _v;
}

/**
 * @function add_Edge
 */
int Graph::add_Edge( Vertex* _u, Vertex* _adjV, int _w ) {

  for( int i = 0; i < numV; ++i ) {

    if( V[i] == _u ) {
      V[i]->add_adjV( _adjV, _w );
    }

  }
}

/**
 * @function add_Edge
 */
int Graph::add_Edge( int _u_key, Vertex* _adjV, int _w ) {

  V[_u_key]->add_adjV( _adjV, _w );
}

/** 
 * @function add_Edge
 */
int Graph::add_Edge( int _u_key, int _v_key, int _w ) {
  V[_u_key]->add_adjV( V[_v_key], _w );
}
