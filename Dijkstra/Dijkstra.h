/**
 * @file Dijkstra.h
 * @author A. Huaman
 */
#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

/**
 * @class Dijkstra
 */
class Dijkstra {

 public:
  Dijkstra();
  ~Dijkstra();
  bool search();
  bool print_Path( int _t );

 private:
  void initialize_SingleSource( int _s_key );
  bool relax( Vertex* _u, Vertex* _v, int _w );
  
  Graph* G;
  int s_key;
  int numV;
};

#endif /** _DIJKSTRA_H_ */
