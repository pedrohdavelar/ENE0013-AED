#ifndef _GUARD_GRAFO
#define _GUARD_GRAFO

#include <set>
#include <map>
#include <string>
#include <queue>

class Edge;

class Node{
public:
  Node(std::string label);
  std::string getLabel();//retorna nome do vertice
private:
  std::string label; //rotulo (identificador) do vertice
  std::set<Edge *> adjacency; //lista de arestas adjacentes
  friend class Graph; //classe Graph tera acesso a todos os membros de objetos Node
};

class Edge{
public:
  Edge(Node* s, Node* f, double w);
  void printMe();
  double cost();
private:
  Node *start; //vertice de inicio da aresta
  Node *finish; //vertice de fim da aresta
  double weight; //peso da aresta do grafo
  friend class Graph;
};

class Graph{
public:
  Graph(bool directed); //construtor
  void addNode(std::string name);//adiciona um vertice a G
  void addEdge(std::string label1, std::string label2, double weight);//adiciona aresta entre vertices de rotulo label1 e label2
  void printAdjacencyList();//imprime a lista de adjacencia dos vertices
  void depthFirstSearch(std::string initLabel);//percurso em profundidade no grafo
  void breadthFirstSearch(std::string initLabel);//percurso em largura no grafo
  std::map<std::string, std::string> findShortestPath(std::string initLabel);//procura caminhos minimos a partir de vertice initLabel
private:
  void createEdge(Node* s, Node* f, double weight);
  void visitUsingDFS(Node* node, std::set<Node*>& notVisited);
  void visit(Node* s);
  std::map<std::string, std::string> dijkstra(Node* start);//alg. de Dijkstra para caminhos minimos

  //ATRIBUTOS
  bool directed; //variável booleana que marca se G é direcionado
  std::map<std::string, Node *> nodeMap;//mapa de labels para os vertices
  std::set<Node *> nodes;  //conjunto de vertices
  std::set<Edge *> edges; //conjunto de arestas
};

#endif
