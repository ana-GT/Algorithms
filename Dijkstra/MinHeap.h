/**
 * @file MinHeap.h
 * @author A. Huaman
 * @date 2012-08-03
 */

#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

/**
 * @class MinHeap
 */
class MinHeap {
 public:

  MinHeap();
  ~MinHeap();

  int Insert( Vertex* _v );
  Vertex* Minimum();
  void Extract_Min();
  int Decrease_Key( Vertex* _v, int _w );

 private:

  inline int Left( int _i );
  inline int Right( int _i );
  inline int Parent( int _i );

  Vertex** S; /**< Data */
  int head;
  int tail;
};

/**
 * @function Left
 */
inline int MinHeap::Left( int _i ) {
  return (_i<<1) + 1;
}


/**
 * @function Right
 */
inline int MinHeap::Right( int _i ) {
  return (_i+1) << 1;
}

/**
 * @function Parent
 */
inline int MinHeap::Parent( int _i ) {
  return (_i-1) >> 1;
}


#endif /** _MIN_HEAP_H_ */
