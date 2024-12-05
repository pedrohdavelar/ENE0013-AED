#include "genQueue.hpp"
#include <iostream>
#include <string>

int main (){
  
  std::string palavra;
  Queue<std::string> fila;
  
  while(std::cin >> palavra){
    fila.enqueue(palavra);
  }

  while (!(fila.isEmpty())){
    std::cout << fila.dequeue() << std::endl;
  }
  return 0;
}