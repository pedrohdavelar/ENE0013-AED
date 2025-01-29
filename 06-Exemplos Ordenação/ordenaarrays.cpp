#include <iostream>
#include <chrono>
#include "sort.h"
#include "busca.h"
#define MAXSIZE 1024

using namespace std;
using namespace std::chrono;

int main(int argc, char const *argv[]) {

  int lista[MAXSIZE];
  int n = 0;
  // int posicao,valor;
  int valor;

  cout << "Digite valores e -1 para encerrar" << endl;
  cin >> valor;
  while (valor > -1) {
    lista[n] = valor;
    n++;
    cin >> valor;
  }


  // insertionsort(lista, n);
  // bubblesort(lista, n);
  selectionsort(lista,n);

  high_resolution_clock::time_point t1 = high_resolution_clock::now();//contagem de tempo

  // heapsort(lista,n);
  // quicksort(lista, 0, n-1);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();//contagem de tempo

  cout << lista[0];
  for (int i = 1; i < n; i++) {
    cout << " " << lista[i];
  }
  cout << endl;
  cout << endl;

  cout  << "Tempo decorrido: "
        << duration_cast<milliseconds>(t2-t1).count()
        << endl;

  // cout << "Digite um inteiro a pesquisar, -1 para encerrar:  ";
  // cin >> valor;
  // while(valor > -1)
  // {
  //   posicao = buscabinaria(lista, n, valor);
  //   // posicao = buscabinariarecursiva(lista, 0, n-1, valor);
  //   if(posicao>-1)
  //     cout << "Encontrado na posicao " << posicao << endl;
  //   else
  //     cout << "Não encontrado" << endl;
  //   cout << "Digite um inteiro a pesquisar, -1 para encerrar:  ";
  //   cin >> valor;
  // }

  return 0;
}
