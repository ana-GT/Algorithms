/**
 * @file Vertex.h
 * @author A. Huaman
 * @date 2012-07-31
 */

#include "Vertex.h"


/**
 * @function Vertex
 * @brief Constructor
 */
Vertex::Vertex(){
  
}

Vertex::Vertex( int _key, 
		int _d, 
		int _parent,
		COLOR _color ) {
  key = _key;
  AdjListV.resize(0);
}

/**
 * @function Vertex
 * @brief Destructor
 */
Vertex::~Vertex(){
  
}

/**
 * @function addAdjV
 */
void Vertex::addAdjV( Vertex* _v ) {
  AdjListV.push_back( _v );
  AdjC.push_back(0);
  AdjF.push_back(0);
}

/**
 * @function addAdjV
 */
void Vertex::addAdjV( Vertex* _v, int _c, int _f ) {
  AdjListV.push_back( _v );
  AdjC.push_back(_c);
  AdjF.push_back(_f);
}

/************ SETTERS ************/

/**
 * @function setKey
 */
void Vertex::setKey( int _key ) {
  key = _key;
}

/**
 * @function set_color
 */
void Vertex::set_color( COLOR _color ) {
  color = _color;
}

/**
 * @function set_d
 * @brief Set edge depth
 */
void Vertex::set_d( int _d ) {
  d = _d;
}

/**
 * @function set_parent
 * @brief Set direct predecessor
 */
void Vertex::set_parent( int _parentKey ) {
  parent = _parentKey;
}

/**
 * @function set_c
 */
bool Vertex::set_c( int _adj_key, int _c ) {

  int i = 0;
  for( std::list<Vertex*>::iterator it = AdjListV.begin(); it != AdjListV.end(); ++it ) {
    if( (*it)->getKey() == _adj_key ) {
      AdjC[i] = _c;
      return true;
    }
    ++i;
  }
  return false;
}

/**
 * @function set_c
 */
bool Vertex::set_c( Vertex* _adj, int _c ) {

  int i = 0;
  for( std::list<Vertex*>::iterator it = AdjListV.begin(); it != AdjListV.end(); ++it ) {
    if( (*it) == _adj ) {
      AdjC[i] = _c;
      return true;
    }
    ++i;
  }
  return false;
}

/**
 * @function set_f
 */
bool Vertex::set_f( int _adj_key, int _f ) {

  int i = 0;
  for( std::list<Vertex*>::iterator it = AdjListV.begin(); it != AdjListV.end(); ++it ) {
    if( (*it)->getKey() == _adj_key ) {
      AdjF[i] = _f;
      return true;
    }
    ++i;
  }
  return false;
}

/**
 * @function set_f
 */
bool Vertex::set_f( Vertex* _adj, int _f ) {

  int i = 0;
  for( std::list<Vertex*>::iterator it = AdjListV.begin(); it != AdjListV.end(); ++it ) {
    if( (*it) == _adj ) {
      AdjF[i] = _f;
      return true;
    }
    ++i;
  }
  return false;
}

/************** A few getters **************/

/**
 * @function get_c
 */
int Vertex::get_c( int _adj_key ) {

  int i = 0;
  for( std::list<Vertex*>::iterator it = AdjListV.begin(); it != AdjListV.end(); ++it ) {
    if( (*it)->getKey() == _adj_key ) {
      return AdjC[i];
    }
    ++i;
  }
  return 0; /** Default if the edge does not exist */
}

/**
 * @function get_c
 */
int Vertex::get_c( Vertex* _adj ) {

  int i = 0;
  for( std::list<Vertex*>::iterator it = AdjListV.begin(); it != AdjListV.end(); ++it ) {
    if( (*it) == _adj ) {
      return AdjC[i];
    }
    ++i;
  }
  return 0;
}

/**
 * @function get_f
 */
int Vertex::get_f( int _adj_key ) {

  int i = 0;
  for( std::list<Vertex*>::iterator it = AdjListV.begin(); it != AdjListV.end(); ++it ) {
    if( (*it)->getKey() == _adj_key ) {
      return AdjF[i];
    }
    ++i;
  }
  return 0;
}

/**
 * @function get_f
 */
int Vertex::get_f( Vertex* _adj ) {
  int i = 0;
  for( std::list<Vertex*>::iterator it = AdjListV.begin(); it != AdjListV.end(); ++it ) {
    if( (*it) == _adj ) {
      return AdjF[i];
    }
    ++i;
  }
  return 0;
}

/**
 * @function isEdge
 */
bool Vertex::isEdge( Vertex* _adj ) {

  for( std::list<Vertex*>::iterator it = AdjListV.begin(); it != AdjListV.end(); ++it ) {
    if( (*it) == _adj ) {
      return true;
    }
  }
    return false;
}

/**
 * @function isEdge
 */
bool Vertex::isEdge( int _adj_key ) {

  for( std::list<Vertex*>::iterator it = AdjListV.begin(); it != AdjListV.end(); ++it ) {
    if( (*it)->getKey() == _adj_key ) {
      return true;
    }
  }
  return false;
}

/**
 * @function outFlow
 */
int Vertex::get_outFlow() {

  int sum = 0;
  for( int i = 0; i < AdjC.size(); ++i ) {
    sum = sum + AdjF[i];
  }
  return sum;
}
