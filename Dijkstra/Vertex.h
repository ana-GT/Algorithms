/**
 * @file Vertex.h
 */

#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <climits>
#include <vector>

#define INF INT_MAX
#define NIL (-1)

/**
 * @class Vertex
 */
class Vertex {

 public:

  Vertex();
  Vertex( int _key, int _d = INF, int _parent = NIL );
  ~Vertex();

  bool set_w( Vertex *_v, int _w );
  bool set_w( int _v_key, int _w ); 
  int get_w( Vertex *_v );
  int get_w( int _v_key );
  int add_adjV( Vertex* _v, int _w );
  
  inline void set_d( int _d );
  inline void set_parent( int _parent );
  inline void set_key( int _key );

  inline int get_d();
  inline int get_parent();
  inline int get_key();

  inline std::vector<Vertex*> get_adjV();
  inline std::vector<int> get_w();

 private:
  int d;
  int parent;
  int key;
  std::vector<Vertex*> adjV;
  std::vector<int> w;
};

/****************INLINE FUNCTIONS **********************/

/**
 * @function
 * @brief
 */
inline void Vertex::set_d( int _d ) {
  d = _d;
}

/**
 * @function
 * @brief
 */
inline void Vertex::set_parent( int _parent ) {
  parent = _parent;
}

/**
 * @function
 * @brief
 */
inline void Vertex::set_key( int _key ) {
  key = _key;
}


/**
 * @function
 * @brief
 */
inline int Vertex::get_d() {
  return d;
}

/**
 * @function
 * @brief
 */
inline int Vertex::get_parent() {
  return parent;
}

/**
 * @function
 * @brief
 */
inline int Vertex::get_key() {
  return key;
}

/**
 * @function get_adjV
 */
inline std::vector<Vertex*> Vertex::get_adjV() {
  return adjV;
}

/** 
 * @function get_w
 */
inline std::vector<int> Vertex::get_w() {
  return w;
}


#endif /** _VERTEX_H_ */ 
