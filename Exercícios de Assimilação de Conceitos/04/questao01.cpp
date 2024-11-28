#include <iostream>
#include <iomanip>

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
  int max(); //retorna o maior valor da lista
  double avg(); //retorna a média
  
private:
  Node *head; //inicio da lista ligada
  Node *tail; //final da lista ligada

};

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

int linkedList::max(){
    int gda_max = head->data;
    
    for (Node* i = head->next; i !=nullptr; i = i->next){
        if (i->data > gda_max){gda_max=i->data;}
    }
    return gda_max;
}

double linkedList::avg(){
    if (isEmpty()){return 0.0;}
    else{
    double soma = 0.0;
    int n = 0;
    for (Node* i = head; i !=nullptr; i = i->next){
        soma += i->data;
        n++;
    }

    return (soma/n);
    }
}


int main (){
    
    //std::cout << "Comecando..." << std::endl;
    linkedList lista;

    int x;

    while(std::cin >> x){lista.addTail(x);}

    std::cout << "Maximo: " << lista.max() << std::endl;
    std::cout << "Media: " << std::fixed << std::setprecision(2) << lista.avg() << std::endl;
    
    return 0;
}