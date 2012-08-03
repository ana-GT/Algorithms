/**
 * @file Graph.h
 * @author A. Huaman
 */

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <climits>
#include <Eigen/Core>

/** Definitions */
#define NIL (-1)
#define INF INT_MAX

/**
 * @enum COLOR
 */
typedef enum {
  WHITE,
  BLACK,
  GRAY
} COLOR;

/**
 * @struct Vertex
 */
struct Vertex{
  COLOR color;
  int d;
  int parent;
  Vertex();
};


/**
 * @class Graph
 */
class Graph {

 public:
  Graph();
  Graph( int _dim_x, int _dim_y, int _dim_z );
  ~Graph();
  void  init();
  int getNumV();
  Vertex* getV( int _index );

 private:
  Vertex *V;
  int *AdjList[];
  int dimX; int dimY; int dimZ;
  int numV;

};

/****** INLINE FUNCTIONS ******/
inline int Graph::getNumV() {
  return numV;
}

#endif /** _GRAPH_H_ */

