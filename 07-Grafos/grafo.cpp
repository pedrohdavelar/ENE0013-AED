#include "grafo.hpp"
#include <iostream>
#include <limits>
#include <list>

//Implementacoes da classe Node
Node::Node(std::string label){
  this->label = label;
  this->adjacency = std::set<Edge *>();
}

std::string Node::getLabel(){
  return this->label;
}
//Final implementacoes da classe Node

//Implementacoes da classe Edge
Edge::Edge(Node *s, Node* f, double w){
  this->start = s;
  this->finish = f;
  this->weight = w;
}

void Edge::printMe(){
  std::cout << this->start->getLabel() << " -> " << this->finish->getLabel();
}

double Edge::cost(){
  return this->weight;
}
//Final implementacoes da classe Edge

//Implementacoes da classe Graph
Graph::Graph(bool directed){
  this->directed = directed;
  this->nodeMap = std::map<std::string, Node *>();
  this->nodes = std::set<Node *>();
  this->edges = std::set<Edge *>();
}

//adiciona um vertice a G
void Graph::addNode(std::string name){
  Node *tmp = new Node(name);
  this->nodes.insert(tmp);
  this->nodeMap[name] = tmp;
}

//adiciona aresta entre vertices de rotulo label1 e label2
void Graph::addEdge(std::string label1, std::string label2, double weight){
  Node *n1 = this->nodeMap[label1];//busca os dois vertices no mapa pelos seus labels
  Node *n2 = this->nodeMap[label2];
  this->createEdge(n1, n2, weight);//cria aresta entre os vertices
  if(!this->directed)//se grafo é nao-direcionado, cria no outro sentido tambem
    this->createEdge(n2, n1, weight);
}

//cria objeto aresta ligando vertices s e f
void Graph::createEdge(Node* s, Node* f, double weight){
  Edge *e = new Edge(s, f, weight);
  this->edges.insert(e);//insere nova aresta no conjunto de arestas do grafo
  s->adjacency.insert(e);//registra aresta que termina em f como adjacente ao vertice s
}

//impressao da lista de adjacencias do grafo
void Graph::printAdjacencyList(){
  for(Node *node : this->nodes){ //comando foreach - percorre cada elemento do conjunto
    std::cout << node->label << " -> ";
    bool first = true;
    for(Edge *arc : node->adjacency){ //comando foreach - percorre cada elemento do conjunto
      if(!first)
        std::cout << ", ";
      std::cout << arc->finish->label;
      first = false;
    }
    std::cout << '\n';
  }
}

//funcao privada de visitacao de um no do grafo
void Graph::visit(Node* s){
  std::cout << s->getLabel() << " visited.\n";
}

//percurso em profundidade no grafo
void Graph::depthFirstSearch(std::string initLabel){
  std::set<Node *> notVisited = this->nodes;
  Node *start = this->nodeMap[initLabel];//recupera o no do grafo de partida
  visitUsingDFS(start, notVisited);//inicia o percurso
  while (notVisited.size()>0) { //se ainda ha vertices nao-visitados
    start=*(notVisited.begin()); //pega um novo vertice de partida
    visitUsingDFS(start,notVisited); //reinicia o percurso
  }
}

void Graph::visitUsingDFS(Node *node, std::set<Node*>& notVisited){
  if(notVisited.find(node)==notVisited.end())
    return; //se ja visitou o no, encerra funcao
  this->visit(node);//visitando...
  notVisited.erase(node);//marca vertice como visitado
  for(Edge *arc : node->adjacency)
    visitUsingDFS(arc->finish, notVisited);
}

//percurso em largura no grafo
void Graph::breadthFirstSearch(std::string initLabel){
  std::set<Node*> notVisited = this->nodes; //conj. de nos nao visitados
  std::queue<Node*> waitlist; //fila de adjacentes a visitar
  Node *node = this->nodeMap[initLabel]; //recupera o no de partida do grafo
  while(notVisited.size()>0){
    waitlist.push(node);
    while (!waitlist.empty()) {
      node = waitlist.front(); //tira da fila o proximo no
      waitlist.pop();
      if(notVisited.find(node)!=notVisited.end()){ //se no nao foi visitado
        this->visit(node);//visitando...
        notVisited.erase(node); //retira do conjunto de nao-visitados
        for(Edge* n : node->adjacency)
          waitlist.push(n->finish); //poe na fila seus nos adjacentes
      }
    }
    if(notVisited.size()>0)//se mesmo apos esvaziar fila, ainda existem nao-visitados
      node = *(notVisited.begin()); //atribui um novo ponto de partida para retomar o percurso
  }
}

std::map<std::string, std::string> Graph::findShortestPath(std::string initLabel){
  Node *start = this->nodeMap[initLabel];
  return this->dijkstra(start);
}


 std::map<std::string, std::string> Graph::dijkstra(Node* start){
  std::map<std::string, double> currDist;
  std::set<Node *> toBeChecked; //todos os nos de G sao copiados para toBeChecked
  std::map<std::string, std::string> predecessor;

  for(Node * v : this->nodes){
    currDist[v->label] = std::numeric_limits<double>::infinity(); //inicializa com distancia "infinita"
    toBeChecked.insert(v);
  }

  Node* first = start;
  currDist[first->label] = 0; //no inicial tem distancia 0

  while (!toBeChecked.empty()) {
    Node *v = *toBeChecked.begin();
    for(Node *next : toBeChecked)//busca vertice v de menor custo/distancia
      if(currDist[next->label] < currDist[v->label])
        v = next;
    toBeChecked.erase(v); //tira v do conj. a checar
    for(Edge *arc : v->adjacency) //para toda aresta adjacente de v
      if(toBeChecked.find(arc->finish) != toBeChecked.end()) //se vertice destino esta em toBeChecked
        if(currDist[arc->finish->label] > (currDist[v->label] + arc->weight)){
          currDist[arc->finish->label] = currDist[v->label] + arc->weight; //atualiza (relaxamento) do custo
          predecessor[arc->finish->label] = v->label;
        }
  }
  return predecessor;
}
