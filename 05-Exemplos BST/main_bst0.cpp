#include <iostream>
#include "genBST0.hpp"

using namespace std;

int main(int argc, char const *argv[]) {

  BST<int> arvore;
  int valor, *resp;

  cin >> valor;
  while (valor >= 0) {
    arvore.insert(valor);
    cin >> valor;
  }

  std::cout << "IN-ORDEM:" << std::endl;
  arvore.inorder();
  std::cout << std::endl;

  std::cout << "LARGURA:" << std::endl;
  arvore.breadthFirst();
  std::cout << std::endl;

  std::cout << "Digite o inteiro a buscar: ";
  cin >> valor;
  while (valor >= 0) {
    resp = arvore.search(valor);
    if (resp)
      std::cout << "Valor "<< (*resp) << " encontrado!" << std::endl;
    else
      std::cout << "Valor não encontrado." << std::endl;
    std::cout << "Digite o inteiro a buscar: ";
    cin >> valor;
  }

  return 0;
}
