#include <iostream>
#include <string>

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
  void print();        //Imprime na saída-padrão todos os elementos da lista, separados por espaço
  void printReverse(); //Imprime na saída-padrão todos os elementos da lista em ordem reversa, separados por espaço

  doubleNode *head; //inicio da lista duplamente ligada
  doubleNode *tail; //final da lista duplamente ligada

};

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
  // for(i=tail; i!=0 && i->data != key; i = i->previous);
  return (i!=0); //se i==0, key nao foi encontrado
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
    head = 0;
    tail = head;
  }
  else
  {
    tail = tail->previous;//final da lista passa para o elemento anterior
    delete tail->next; //apaga
    tail->next = 0;//novo final nao tem sucessor
  }
  return retvalue;
}

void doubleLinkedList::print()
{
    if (isEmpty()){
        return;
    }
    doubleNode *i;
    for (i = head; i->next != 0; i = i->next){
        std::cout << i->data << " ";
    }
    std::cout << i->data << std::endl;    //precisa imprimir o ultimo numero (next=0)
}

void doubleLinkedList::printReverse()
{
    if (isEmpty()){
        return;
    }
    doubleNode *i;
    for (i = tail; i->previous != 0; i = i->previous){
        std::cout << i->data << " ";
    }
    std::cout << i->data << std::endl;   //precisa imprimir o primeiro numero (previous=0)
}

int main (){

    doubleLinkedList lista;      //topo<->l1<->l2<->...<->ln<->base 
    int n;                       //topo = inicio da lista; base = fim da lista
    std::string descartadas = "";

    while(std::cin >> n){
        if(n==0){break;}else{ //loop principal; break quando for inserido 0
            descartadas.clear();     //reinicializa a string para a iteração
            
            for(int i=1;i<=n;i++){lista.addTail(i);} //preenche a lista com n numeros de 1 a n ex: 1 2 3 4

            while(lista.head->next!=0){   //head->next!=0 significa que ainda ha 2 membros na lista
                lista.addTail(lista.head->data); //adiciona a carta do topo a base
                lista.deleteHead(); //remove a carta que foi passada do topo a base
                
                if (lista.head->next!=0){ //se ainda houver 2+ cartas entao descarta a carta do topo
                    descartadas+=std::to_string(lista.deleteHead()); //std::to_string para poder fazer a concatenação de int para str
                    if (lista.head->next!=0){ //se ainda houver 2+ cartas entao ainda vai haver mais um descarte
                        descartadas+=", ";    //entao adicionamos a virgula a string para a saida ter a formatação esperada
                        }
                    }
            }
            std::cout << "Cartas descartadas: " << descartadas << std::endl;
            std::cout << "Carta remanescente: " << lista.deleteHead() << std::endl; //com o ultimo delete, a lista fica vazia para a proxima iteração
            }
        }
    return 0;
}