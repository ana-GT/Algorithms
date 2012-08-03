/**
 * @file BFS.h
 * @author A. Huaman
 * @date 2012-08-01
 */

#ifndef _BFS_H_
#define _BFS_H_

#include "Queue.h"
#include "Graph.h"


/**
 * @function BFS
 */

class BFS {
 public:
  BFS();
  ~BFS();
  template<class Tv>	
    void search( Graph<Tv>* _g, int _s );
  template<class Tv>
    Tv* init( Graph<Tv>* _g, int _s );
  template<class Tv>
    std::list<int> getPath( Graph<Tv>* _g, int _s, int _t );
  template<class Tv>
    std::vector<int> getPathVector( Graph<Tv>* _g, int _s, int _t );
};

/**
 * @function Constructor
 */
BFS::BFS() {
}

/**
 * @function Destructor
 */
BFS::~BFS() {
}


/**
 * @function Init
 * @brief Initialize all vertices AND the start specially
 */
template<class Tv>
  Tv* BFS::init( Graph<Tv>* _g, int _s ) {

  Tv** vp;

  //-- Initialize all vertices
  vp = _g->getVertexPointer(0);
  for( size_t i = 0; i < _g->getNumV(); ++i ) {
    //v = _g->getVertex(i);
    (*vp)->set_color( WHITE );
    (*vp)->set_d( INF );
    (*vp)->set_parent( NIL );
    ++vp;
  }  

  //-- Set start vertex
  Tv* s;
  s = _g->getVertex( _s );
  s->set_color( GRAY );
  s->set_d( 0 );
  s->set_parent( NIL );

  return s;
}

/**
 * @function search
 */
template<class Tv>
  void BFS::search( Graph< Tv>* _g, int _s ) {

  Tv* s = init( _g, _s );
  
  //-- Set Queue
  Queue<Vertex> Q;
 
  //-- Push  start vertex
  Q.Enqueue( s );

  // Loop
  Tv* u;
  int u_key;
  int u_d;

  while( !Q.isEmpty() ) {

    u = Q.Dequeue();
    u_key = u->getKey();
    u_d = u->get_d();

    int numAdj = u->getSizeAdj();
    Tv* v;
    std::list<Tv*> adj;
    adj = u->getAdjListV();

    typename std::list<Tv*>::iterator it;

    for( it = adj.begin(); it != adj.end(); ++it ) {
      v = *(it);
      if( v->get_color() == WHITE ) {
	v->set_color( GRAY );
	v->set_d( u_d + 1);
	v->set_parent( u_key );
	Q.Enqueue( v );
      }
    }
    u->set_color( BLACK );
  } 
  
}

/**
 * @function getPath
 */
template<class Tv>
std::list<int> BFS::getPath( Graph<Tv>* _g, int _s, int _t ) {

  std::list<int> path;
  Tv* v;
  int parent;

  if( ( _g->getVertex(_s) )->get_parent() != NIL ) {
    printf( " --(!) BFS: Start node is not root. Exiting! \n" );
    return path;
  }


  else {
    v = _g->getVertex(_t);
    parent = v->get_parent();

    if( parent == NIL ) {
      /* printf("--(!) No path to root, bang! Exiting \n"); */
      return path;
    }

    path.push_back( v->getKey() );

    while( parent != NIL ) {
      path.push_back( parent );
      v = _g->getVertex( parent );
      parent = v->get_parent();
    }
  }

  return path;
}

/**
 * @function getPath
 */
template<class Tv>
std::vector<int> BFS::getPathVector( Graph<Tv>* _g, int _s, int _t ) {

  std::vector<int> path;
  Tv* v;
  int parent;

  if( ( _g->getVertex(_s) )->get_parent() != NIL ) {
    printf( " --(!) Start node is not root. Exiting! \n" );
    return path;
  }


  else {
    v = _g->getVertex(_t);
    parent = v->get_parent();

    if( parent == NIL ) {
      /* printf("--(!) No path to root, bang! Exiting \n"); */
      return path;
    }

    path.push_back( v->getKey() );

    while( parent != NIL ) {
      path.push_back( parent );
      v = _g->getVertex( parent );
      parent = v->get_parent();
    }
  }

  int n = path.size();
  std::vector<int> path_back( n );
  for( int i = 0; i < n; ++i ) {
    path_back[i] = path[n-1-i];
  }

  return path_back;
}

#endif /** _BFS_H_ */
