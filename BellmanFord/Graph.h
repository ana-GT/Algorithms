/**
 * @file Graph.h
 * @brief Graph
 * @author A. Huaman
 * @date August 3rd, 2012
 */

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "Vertex.h"

/**
 * @class Graph
 */
class Graph {

 public:
  Graph( int _N );
  ~Graph();

  int set_Vertex( Vertex* _v, int _key );
  int add_Edge( Vertex* _u, Vertex* _adjV, int _w );
  int add_Edge( int _u_key, Vertex* _adjV, int _w );
  int add_Edge( int _u_key, int _v_key, int _w );

  inline int get_NumV();
  inline Vertex* get_Vertex( int _i );
  inline Vertex** get_VertexPointer( int _i );

 private:
  int numV;
  Vertex** V;
};

/******************* INLINE FUNCTIONS *****************/

/**
 * @function get_NumV
 */
inline int Graph::get_NumV() {
  return numV;
}

/**
 * @function get_Vertex
 */
inline Vertex* Graph::get_Vertex( int _i ) {
  return V[_i];
}

/**
 * @function get_VertexPointer
 */
inline Vertex** Graph::get_VertexPointer( int _i ) {
  return &V[_i];
}

#endif /** _GRAPH_H_  */
