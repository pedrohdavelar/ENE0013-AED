#include "arvore.hpp"
#include <string>
#include <iostream>

using namespace std;

//funcao principal do programa
int main(int argc, char const *argv[]) {

  //instanciando os objetos
  Arvore arv("Jacaranda acutifolia", "Jacaranda");
  Arvore arv2("Araucaria angustifolia", "Araucaria");
  Arvore arv3; //declara variavel sem argumentos - invoca construtor padrao

  //chamadas da funcao-membro dos objetos
  cout << "Meu nome cientifico e " << arv.meu_nome(0) << endl;
  cout << "Meu nome popular e " << arv2.meu_nome(1) << endl;
  cout << "Meu nome cientifico e " << arv3.meu_nome(0) << endl;

  return 0;
}