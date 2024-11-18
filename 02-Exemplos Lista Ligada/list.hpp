#ifndef LIST_GUARD
#define LIST_GUARD

class Node
{
public:
  int data; //chave
  Node *next; //apontador para o proximo nó

  //construtores
  Node();
  Node(int, Node*);
};


class linkedList
{
public:
  linkedList();  //construtor
  ~linkedList(); //destrutor

  //metodos
  bool isEmpty(); //verifica se esta vazia
  bool inList(int); //busca inteiro passado na lista e retorna true se positivo
  void addHead(int); //adiciona inteiro ao inicio da lista
  void addTail(int); //adiciona inteiro ao final da lista
  int deleteHead(); //remove primeiro elemento da lista e o retorna
  int deleteTail(); //remove ultimo elemento da lista e o retorna

private:
  Node *head; //inicio da lista ligada
  Node *tail; //final da lista ligada

};

#endif
