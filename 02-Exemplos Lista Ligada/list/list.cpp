#include "list.hpp"

Node::Node()
{
  next = 0;
}

Node::Node(int i, Node *prox)
{
  data = i;
  next = prox;
}

linkedList::linkedList()  //construtor
{
  head = 0;//inicio e final da lista apontam para NULL
  tail = 0;
}

linkedList::~linkedList() //destrutor
{
  Node *p;
  while (head != 0) { //enquanto lista não está vazia, desalocar memória
    p = head->next;
    delete head; //destroi elemento apontado por head
    head = p; //inicio da lista passa a ser o elemento seguinte
  }
}

//metodos
bool linkedList::isEmpty()
{
  return (head == 0);
}

bool linkedList::inList(int key)
{
  Node *i;
  //caminha com apontador i ate o fim da lista OU ate encontrar key
  for (i = head; i != 0 && i->data !=  key; i = i->next);
  return (i != 0);
}

void linkedList::addHead(int info)
{
  head = new Node(info, head);
  if (tail == 0) //se nao havia nó na lista
    tail = head; //tail também aponta para o unico elemento existente
}

void linkedList::addTail(int info)
{
  if (tail != 0) //se a lista nao esta vazia
  {
    tail->next = new Node(info, 0);
    tail = tail->next;
  }
  else
  {
    tail = new Node(info,0);
    head = tail; //somente 1 elemento -> head e tail apontam para ele
  }
}

int linkedList::deleteHead()
{
  int retvalue = head->data;
  Node *temp = head;
  if(head == tail) //se só há um elemento na lista
  {
    head =  0;
    tail = head;
  }
  else
    head = head->next;
  delete temp; //destroi o elemento inicial antigo
  return retvalue;
}

int linkedList::deleteTail()
{
  int retvalue = tail->data;
  if (tail == head) //só há um elemento na lista
  {
    delete head;
    head = tail = 0;
  }
  else
  {
    Node *temp;
    //procura o antecessor do ultimo elemento da lista
    for(temp = head; temp->next != tail; temp = temp->next );
    delete tail;
    tail = temp; //antecessor passa a ser o ultimo da lista
    tail->next = 0;
  }
  return retvalue;
}
