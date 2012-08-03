/**
 * @file Vertex.h
 * @brief Vertex generic type
 * @author A. Huaman
 * @date 2012-07-31
 */

#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <climits>
#include <list>
#include <vector>
#include <stdio.h>

#define INF INT_MAX 
#define NIL (-1)

/**
 * @enum COLOR
 */
typedef enum {
  WHITE,
  BLACK,
  GRAY
} COLOR;

/**
 * @class Vertex
 */
class Vertex {

 public:
  Vertex();
  Vertex( int _key, 
	  int _d = INF, 
	  int _parent = NIL,
	  COLOR _color = WHITE );
  ~Vertex();
  
  void addAdjV( Vertex* _v );
  void addAdjV( Vertex* _v, int _c, int _f );

  bool isEdge( Vertex* _adj );
  bool isEdge( int _adj_key );

  void setKey( int _key );
  void set_color( COLOR _color );
  void set_d( int _d );
  void set_parent( int _parentKey );

  bool set_c( int _adj_key, int _c );
  bool set_c( Vertex* _adj, int _c );
  bool set_f( int _adj_key, int _f );
  bool set_f( Vertex* _adj, int _f );

  inline int getKey();
  inline COLOR get_color();
  inline int get_d();
  inline int get_parent();

  int get_c( int _adj_key );
  int get_c( Vertex* _adj );
  int get_f( int _adj_key );
  int get_f( Vertex* _adj );

  int get_outFlow();

  inline int getSizeAdj();
  inline std::list<Vertex*> getAdjListV();
  inline std::vector<int> getAdjC();
  inline std::vector<int> getAdjF();

 private:
  std::list<Vertex*> AdjListV;
  //-- For Ford
  std::vector<int> AdjC;
  std::vector<int> AdjF;

  int key;
  int parent; 
  int d;
  COLOR color;  

};

/***************** INLINE *****************/

/**
 * @function getKey
 */
inline int Vertex::getKey() {
  return key;
}

/**
 * @function get_color
 */
inline COLOR Vertex::get_color() {
  return color;
}

/**
 * @function get_d
 */
inline int Vertex::get_d() {
  return d;
}

/**
 * @function get_parent
 */
inline int Vertex::get_parent() {
  return parent;
}

/**
 * @function getSizeAdj
 */
inline int Vertex::getSizeAdj() {
  return AdjListV.size();
}

/**
 * @function getAdjListV
 */
inline std::list<Vertex*> Vertex::getAdjListV() {
  return AdjListV;
}

/**
 * @function getAdjC
 */
inline std::vector<int> Vertex::getAdjC() {
  return AdjC;
}

/**
 * @function getAdjF
 */
inline std::vector<int> Vertex::getAdjF() {
  return AdjF;
}

#endif /** _VERTEX_H_ */
