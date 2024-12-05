//**********************  genQueue.hpp  *************************
//     generic queue implemented with doubly linked list

#ifndef DLL_QUEUE
#define DLL_QUEUE

#include <list>

template<class T>
class Queue {
public:
  Queue() {
    lst = std::list<T>();
  }

  void clear() {
      lst.clear();
  }

  bool isEmpty(){
      return lst.empty();
  }

  T& front() {
      return lst.front();
  }

  T dequeue() {
      T el = lst.front(); //copia do primeiro elemento
      lst.pop_front(); //remocao do primeiro elemento
      return el;
  }

  void enqueue(const T& el) {
      lst.push_back(el);
  }

private:
  std::list<T> lst;
};

#endif
