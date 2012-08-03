/**
 * @file Queue.h
 * @author A. Huaman
 */
#ifndef _QUEUE_
#define _QUEUE_

/**
 * @class Queue
 */
template<class T, int N>
class Queue {

 public:

  Queue();
  ~Queue();
  void Enqueue( T _x );
  T Dequeue();
  bool Queue_Empty();

 private:
  int head;
  int tail;
  int size;
  T Q[N];
};

/**
 * @function Queue
 * @brief Constructor
 */
template<class T, int N>
  Queue<T,N>::Queue() {
  
  head = 0;
  tail = 0;
  size = N;
}

/**
 * @function ~Queue
 * @brief Destructor
 */
template<class T, int N>
  Queue<T,N>::~Queue() {
  
}

/**
 * @function Enqueue
 * @brief Add an element to the Queue
 */
template<class T, int N>
 void Queue<T,N>::Enqueue( T _x ) {

  if( tail == size ) {
    throw( "(X) Enqueue: Overflow! \n" );
  }

  else {
    Q[tail] = _x;
    tail = tail + 1;
  }
}

/**
 * @function Dequeue
 * @brief Remove an element to the Queue
 */
template<class T, int N>
 T Queue<T,N>::Dequeue() {

  T x;
  if( head == tail ) {
    throw( "(X) Dequeue: Underflow! \n" );
  }
  else {
    x = Q[head];
    head = head + 1;
  }

  return x;
}

/**
 * @function Queue_Empty
 */
template<class T, int N>
  bool Queue<T,N>::Queue_Empty() {
  if( head == tail ) {
    return true;
  }
  else {
    return false;
  }
}

#endif /** _QUEUE_H_ */
