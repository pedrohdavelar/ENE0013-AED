#include "doubleStack.hpp"
#include <iostream>

doubleStack::doubleStack(int max_elements){
  this->data = new double[max_elements];
  this->topo = -1;
  this->maxsize = max_elements;
}

doubleStack::~doubleStack(){
  delete[] this->data;
}

double doubleStack::pop(){ //remove e retorna topo da pilha
  if(!this->isEmpty()){
    double saida = this->data[this->topo];
    this->topo--;
    return saida;
  }
  else{
    std::cout << "ERRO! PILHA VAZIA!" << '\n';
    return -1;
  }
}

void doubleStack::push(double x){ //insere no topo da pilha
  if(this->topo < this->maxsize-1){
    this->topo++;
    this->data[this->topo] = x;
  }
  else
    std::cout << "ERRO! PILHA CHEIA!" << '\n';
}

double doubleStack::peek(){ //somente consulta valor do topo
  if(!this->isEmpty())
    return this->data[this->topo];
  {
    std::cout << "ERRO! PILHA VAZIA!" << '\n';
    return -1;
  }
}

bool doubleStack::isEmpty(){ //true se pilha estiver vazia
  return (this->topo==-1);
}

int main (){
  doubleStack pilha;
  int n;
  while(std::cin >> n){
    pilha.push(n);
  }

  while (!(pilha.isEmpty())){
    std::cout << pilha.peek() << std::endl;
    pilha.pop(); 
  }
  return 0;
}