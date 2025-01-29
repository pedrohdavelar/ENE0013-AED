#ifndef LIST_GUARD
#define LIST_GUARD

class doubleNode
{
public:
  int data; //chave
  doubleNode *previous, *next; //apontador para o antecessor e o proximo nó

  //construtores
  doubleNode();
  doubleNode(int, doubleNode*, doubleNode*);
};


class doubleLinkedList
{
public:
  doubleLinkedList();  //construtor
  ~doubleLinkedList(); //destrutor

  //metodos
  bool isEmpty();
  bool inList(int);
  void addHead(int);
  void addTail(int);
  int deleteHead();
  int deleteTail();
  void sort();
  void show();

private:
  doubleNode *head; //inicio da lista duplamente ligada
  doubleNode *tail; //final da lista duplamente ligada

};

#endif
