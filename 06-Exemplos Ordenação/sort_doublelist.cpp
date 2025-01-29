#include "sort_doublelist.h"
#include <iostream>

doubleNode::doubleNode()
{
  previous = 0;
  next = 0;
}

doubleNode::doubleNode(int i, doubleNode *prev = 0, doubleNode *prox = 0)
{
  data = i;
  previous = prev;
  next = prox;
}

doubleLinkedList::doubleLinkedList()  //construtor
{
  head = 0;//inicio e final da lista apontam para endereco vazio/NULL
  tail = 0;
}

doubleLinkedList::~doubleLinkedList() //destrutor
{
  doubleNode *p;
  while (head != 0) { //enquanto lista não está vazia, desalocar memória
    p = head->next;
    delete head; //destroi elemento apontado por head
    head = p; //inicio da lista passa a ser o elemento seguinte
  }
}

//metodos
bool doubleLinkedList::isEmpty()
{
  return (head == 0);
}

bool doubleLinkedList::inList(int key)
{
  doubleNode *i;
  //caminha com apontador i ate o fim da lista OU ate encontrar key
  for (i = head; i != 0 && i->data !=  key; i = i->next);
  return (i != 0);
}

void doubleLinkedList::addHead(int info)
{
  doubleNode *tmp = new doubleNode(info, 0, head);
  if(head != 0)
    head->previous = tmp;
  head = tmp;
  if (tail == 0) //se nao havia nó na lista
    tail = head; //tail também aponta para o unico elemento existente
}

void doubleLinkedList::addTail(int info)
{
  doubleNode *tmp = new doubleNode(info, tail, 0);
  if (tail != 0) //se a lista nao esta vazia
  {
    tail->next = tmp;
    tail = tail->next;
  }
  else
  {
    tail = tmp;
    head = tail; //somente 1 elemento -> head e tail apontam para ele
  }
}

int doubleLinkedList::deleteHead()
{
  int retvalue = head->data;
  if(head == tail) //se só há um elemento na lista
  {
    delete head;
    head = tail = 0;
  }
  else{
    head = head->next; //comeco da lista passa para o proximo elemento
    delete head->previous; //apaga
    head->previous = 0; //novo comeco nao tem antecessor
  }

  return retvalue;
}

int doubleLinkedList::deleteTail()
{
  int retvalue = tail->data;
  if (tail == head) //só há um elemento na lista
  {
    delete head;
    head = tail = 0;
  }
  else
  {
    tail = tail->previous;//final da lista passa para o elemento anterior
    delete tail->next; //apaga
    tail->next = 0;//novo final nao tem sucessor
  }
  return retvalue;
}

//insertion sort
void doubleLinkedList::sort()
{
  doubleNode *i,*j;
  int toInsert;

  for(i = head->next; i != 0; i = i->next)
  {
    toInsert = i->data; //elemento a inserir
    j = i;
    while (j != head && toInsert < (j->previous)->data) //procura onde inserir, ordem do AND importante!
    {
      j->data = (j->previous)->data;
      j = j->previous;
    }
    j->data = toInsert;
  }
}

void doubleLinkedList::show()
{
  std::cout << head->data;
  for (doubleNode *i = head->next; i != 0; i = i->next) {
    std::cout << " " << i->data;
  }
  std::cout << std::endl;
}
