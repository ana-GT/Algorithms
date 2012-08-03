/**
 * @file Ford.h
 * @author A. Huaman
 * @date 2012-08-01
 */

#ifndef _FORD_H_
#define _FORD_H_

#include "Graph.h"

/**
 * @class Ford
 */
class Ford {

 public:
  Ford();
  ~Ford();
  template<class Tv>
    Graph<Tv>* get_Gf( Graph<Tv>* _g );
  template<class Tv>
    int maxFlow( Graph<Tv>* _g, int _s, int _t );
  template<class Tv>
    void printFlow( Graph<Tv>* _g );
};

/**
 * @function Ford
 * @brief Constructor
 */
Ford::Ford() {

}

/**
 * @function Ford
 * @brief Destructor
 */
Ford::~Ford() {

}

/**
 *  @function get_Gf
 * @brief Get residual graph
 */
template<class Tv>
  Graph<Tv>* Ford::get_Gf( Graph<Tv>* _g ) {

  //-- Create a new graph
  int n =  _g->getNumV();
  Graph<Vertex>* gf = new Graph<Vertex>(n);

  //-- Store default elements
  for( int i = 0; i < n; ++i ) {
    gf->setVertex( i , new Vertex(i) );
  }

  //-- Add adj
  Vertex* u; Vertex* v;
  for( int i = 0; i < n; ++i ) {

    u = _g->getVertex(i);
    std::list<Vertex*> adj = u->getAdjListV();
    
    for( std::list<Vertex*>::iterator it = adj.begin(); it != adj.end(); ++it ) {

      int f = u->get_f( *it );
      int cf = u->get_c( *it ) - f;
   
      Vertex* uf = gf->getVertex(i);
      Vertex* vf = gf->getVertex( (*it)->getKey() ); 

      if( cf > 0 ) {
	uf->addAdjV( vf, cf, 0 );
      }
      if( f > 0 ) {
	vf->addAdjV( uf, f, 0 );
      }
    
    } 
  }
  return gf;
}

/**
 * @function maxFlow
 */
template<class Tv>
int Ford::maxFlow( Graph<Tv>* _g, int _s, int _t ) {

  int n = _g->getNumV();

  // Init all flows to zero
  Vertex* u;
  for( int i = 0; i < n; ++i ) {
    u = _g->getVertex(i);
    std::list<Vertex*> adj = u->getAdjListV();
    
    for( std::list<Vertex*>::iterator it = adj.begin(); it != adj.end(); ++it ) {
      u->set_f( *it, 0);     
    } 
  }

  // Search for a path in the residual network
  Graph<Vertex>* gf = get_Gf( _g );
  BFS b;
  b.search( gf, _s );
  std::vector<int> p = b.getPathVector( gf, _s, _t );

  // Loop
  int pn = p.size();
  int a = 0;

  while( pn > 0 ) {
    // Find min cf in p
    int min_cf = 2000000;
    for( int i = 0; i < pn - 1; ++i ) {
      Vertex* a = gf->getVertex( p[i] );
      int cf = a->get_c( p[i+1] );
      if( cf < min_cf ) {
	min_cf = cf;
      }
    }

    // For each edge
    for( int i = 0; i < pn -1; ++i ) {
      Vertex* b = _g->getVertex( p[i] );
      if( b->isEdge( p[i+1] ) == true ) {
	int f = b->get_f( p[i+1] );
	b->set_f( p[i+1], f + min_cf );
      }
      else {
	Vertex* c = _g->getVertex( p[i+1] );
	if( c->isEdge( b ) != true ) {
	  printf("Darn, something is wrong -- calling from maxFlow! \n");
	}
	int f = c->get_f( b );
	c->set_f( b, f - min_cf );
      }
    }
   
    // Check path
    delete gf;
    gf = get_Gf( _g );
    b.search( gf, _s );
    p = b.getPathVector( gf, _s, _t );
    pn = p.size();

    a++;
  }
  // printf("Out of loop \n");
  Vertex* s = _g->getVertex(_s);
  

  return s->get_outFlow();
}

/**
 * @function printFlow
 */
template<class Tv>
void Ford::printFlow( Graph<Tv>* _g ) {
  
  int n = _g->getNumV();
  Vertex* u;

    printf("\n** Printing Flow Edges ** \n");
  for( int i = 0; i < n; i++ ) {
    u = _g->getVertex(i);
    std::list<Vertex*> adj = u->getAdjListV();
    std::vector<int> c = u->getAdjC();
    std::vector<int> f = u->getAdjF();
    std::list<Vertex*>::iterator it;

    int ind = 0;
    int ukey = u->getKey();
    for( it = adj.begin(); it != adj.end(); ++it ) {
      printf(" * Edge: (%d, %d): %d/%d \n", ukey, (*it)->getKey(), f[ind], c[ind] );
      ind++;
    }
  }
}


#endif /** _FORD_H_ */
