#include <iostream>
#include "genBST2.hpp"

using namespace std;

int main(int argc, char const *argv[]) {

  BST<int> arvore;
  int valor;

  cin >> valor;
  while (valor >= 0) {
    arvore.insert(valor);
    cin >> valor;
  }

  std::cout << "IN-ORDEM:" << std::endl;
  arvore.inorder();
  std::cout << std::endl;
/*
  std::cout << "PRE-ORDEM:" << std::endl;
  arvore.preorder();
  std::cout << std::endl;

  std::cout << "POS-ORDEM:" << std::endl;
  arvore.postorder();
  std::cout << std::endl;

  std::cout << "LARGURA:" << std::endl;
  arvore.breadthFirst();
  std::cout << std::endl;
*/
  std::cout << "Digite o inteiro a remover: ";
  cin >> valor;
  while (valor >= 0) {
    //arvore.findAndDeleteByCopying(valor);
    arvore.findAndDeleteByMerging(valor);
    arvore.inorder();
    std::cout << std::endl;
    std::cout << "Digite o inteiro a remover: ";
    cin >> valor;
  }

  return 0;
}
