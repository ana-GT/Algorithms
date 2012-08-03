/**
 * @file Queue.h
 * @author A. Huaman
 * @date 2012-07-31
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

/**
 * @class Queue
 */
template<class T>
class Queue{

 public:
  Queue();
  ~Queue();
  void Enqueue( T* _x );
  T* Dequeue();
  inline bool isEmpty();
  inline int size();

 private:
  std::list<T*> Q;
};

/**
 * @function Queue
 * @brief Constructor
 */
template<class T>
Queue<T>::Queue() {
}

/**
 * @function ~Queue
 * @brief Destructor
 */
template<class T>
Queue<T>::~Queue() {
}

/**
 * @function Enqueue
 * @brief Add element to queue
 */
template<class T>
void Queue<T>::Enqueue( T* _x ) {
  Q.push_back( _x );
}

/**
 * @function Dequeue
 * @brief Pop from queue
 */
template<class T>
T* Queue<T>::Dequeue() {

  T* x = *( Q.begin() );
  Q.pop_front();
  return x;
}

/**
 * @function isEmpty
 * @brief Is Empty?
 */
template<class T>
inline bool Queue<T>::isEmpty() {
  if( Q.size() > 0 ) { return false; }
  else { return true; }
}


/**
 * @function size
 */
template<class T>
inline int Queue<T>::size() {
  return Q.size();
}

#endif /** _QUEUE_H_ */
