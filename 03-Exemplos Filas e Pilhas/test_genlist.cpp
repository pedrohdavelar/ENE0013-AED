#include "genListStack.hpp"
#include <iostream>
#include <string>

int main (){
  
  std::string palavra;
  LLStack<std::string> pilha;
  
  while(std::cin >> palavra){
    pilha.push(palavra);
  }

  while (!(pilha.isEmpty())){
    std::cout << pilha.pop() << std::endl;
  }
  return 0;
}