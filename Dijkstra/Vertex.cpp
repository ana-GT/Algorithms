/**
 * @file Vertex.cpp
 * @author A. Huaman
 * @date August 3rd, 2012
 */

#include "Vertex.h"

/**
 * @function Vertex
 * @brief Constructor
 */
Vertex::Vertex() {

  adjV.resize(0);
  w.resize(0);
}

Vertex::Vertex( int _key, int _d, int _parent ) {

  adjV.resize(0);
  w.resize(0);

  key = _key;
  d = _d;
  parent = _parent;
}

/**
 * @function ~Vertex
 * @brief Destructor
 */
Vertex::~Vertex() {

  adjV.resize(0);
  w.resize(0);
}

/**
 * @function set_W
 */
bool Vertex::set_w( Vertex *_v, int _w ) {
  
  for( int i = 0; i < adjV.size(); ++i ) {
    if( adjV[i] == _v ) {
      w[i] = _w;
      return true;
    }
  }
  
  return false;
}

/**
 * @function set_W
 */
bool Vertex::set_w( int _v_key, int _w ) {

  for( int i = 0; i < adjV.size(); ++i ) {
    if( adjV[i]->get_key() == _v_key ) {
      w[i] = _w;
      return true;
    }
  }
  
  return false;
}

/**
 * @function get_w
 * @brief
 */
int Vertex::get_w( Vertex *_v ) {

  for( int i = 0; i < adjV.size(); ++i ) {
    if( adjV[i] == _v ) {
      return w[i];
    }
  }
  
  return INF;
}

/**
 * @function
 * @brief
 */
int Vertex::get_w( int _v_key ) {

  for( int i = 0; i < adjV.size(); ++i ) {
    if( adjV[i]->get_key() == _v_key ) {
      return w[i];
    }
  }
  
  return INF;
}


/**
 * @function add_adjV
 */
int Vertex::add_adjV( Vertex* _v, int _w ) {

  adjV.push_back( _v );
  w.push_back( _w );

  return adjV.size();
}
