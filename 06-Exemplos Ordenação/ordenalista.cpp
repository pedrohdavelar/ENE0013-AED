#include <iostream>
#include "sort_doublelist.h"

using namespace std;

int main(int argc, char const *argv[]) {

  doubleLinkedList lista;
  int valor;
  cout << "Digite valores e -1 para parar" << endl;
  cin >> valor;
  while (valor != -1) {
    lista.addTail(valor);
    cin >> valor;
  }

  lista.show();

  lista.sort();
  lista.show();

  return 0;
}
