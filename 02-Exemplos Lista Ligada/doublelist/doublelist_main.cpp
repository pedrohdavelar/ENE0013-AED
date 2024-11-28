#include "doublelist.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {

  doubleLinkedList lista;

  lista.addHead(50);
  lista.addHead(8);
  lista.addHead(10);

  while (!lista.isEmpty()) {
    std::cout << lista.deleteHead() << " -> ";
  }
  std::cout << std::endl;


  lista.addTail(10);
  lista.addTail(8);
  lista.addTail(50);

  while (!lista.isEmpty()) {
    std::cout << lista.deleteTail() << " <- ";
  }
  std::cout << std::endl;

  return 0;
}
