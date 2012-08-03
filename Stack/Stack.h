/**
 * @file Stack.h
 * @author A. Huaman
 * @date 2012-07-23
 */

/**
 * @class Stack
 */
template <class T, int N>
class Stack {

 public:
  Stack();
  ~Stack();
  bool Stack_Empty();
  void Push( T _x );
  T Pop();

 private:
  T S[N];
  int top;
};

/**
 * @function Stack
 * @brief Constructor
 */
template <class T, int N>
  Stack<T,N>::Stack() {
  
  top = -1;
}

/**
 * @function ~Stack
 * @brief Destructor
 */
template <class T, int N>
  Stack<T,N>::~Stack() {
}

/**
 * @function Stack_Empty
 * @brief Check if there are elements on stack
 */
template <class T, int N>
  bool Stack<T,N>::Stack_Empty() {
  if( top == -1 ) {
    return true;
  }
  else {
    return false;
  }
}

/**
 * @function Push
 * @brief Add an element to stack
 */
template <class T, int N>
  void Stack<T,N>::Push( T _x ) {
  top = top + 1;

  if( top == N ) {
    throw( "(X) Error overflow! \n" );
  }
  else {
    S[top] = _x;
  }
} 

/**
 * @function Pop
 * @brief Pop an element from the Stack
 */
template <class T, int N>
  T Stack<T,N>::Pop() {

  if( Stack_Empty() == true ) {
    throw ("(X) Error underflow! \n");
  }

  else {
    top = top - 1;
    return S[top+1];
  }
}
