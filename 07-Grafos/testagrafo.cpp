#include "grafo.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  Graph g(false);//grafo ponderado nao-direcionado
  string fonte;

  //adicionando aeroportos como vertices
  g.addNode("BSB");
  g.addNode("SDU");
  g.addNode("CGH");
  g.addNode("GRU");
  g.addNode("GYN");

  g.addEdge("BSB", "SDU",780);
  g.addEdge("BSB", "GYN",200);
  g.addEdge("BSB", "GRU",1100);
  g.addEdge("BSB", "CGH",1000);
  g.addEdge("SDU", "CGH",600);
  g.addEdge("GYN", "GRU",900);

  g.printAdjacencyList();

  cout << "Informe o vertice de origem: ";
  cin >> fonte;
  cout << "Percurso em profundidade:\n";
  g.depthFirstSearch(fonte);
  cout << "Percurso em largura:\n";
  g.breadthFirstSearch(fonte);

  return 0;
}
