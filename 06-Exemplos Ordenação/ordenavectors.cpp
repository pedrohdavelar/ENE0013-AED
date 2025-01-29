#include <iostream>
#include "sort_vector.h"

using namespace std;

int main(int argc, char const *argv[]) {

  std::vector<int> lista;
  int valor;
  cout << "Digite valores e -1 para parar" << endl;
  cin >> valor;
  while (valor != -1) {
    lista.push_back(valor);
    cin >> valor;
  }

  insertionsort(lista);
  // bubblesort(lista);
  // selectionsort(lista);
  // quicksort(lista, 0, lista.size()-1);

  cout << lista[0];
  for (size_t i = 1; i < lista.size(); i++) {
    cout << " " << lista[i];
  }
  cout << endl;

  return 0;
}
