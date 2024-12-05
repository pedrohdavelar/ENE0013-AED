#ifndef DOUBLE_STACK
#define DOUBLE_STACK

class doubleStack{
public:
  doubleStack(int max_elements = 1024);
  ~doubleStack();

  double pop(); //remove e retorna topo da pilha
  void push(double); //insere no topo da pilha
  double peek(); //somente consulta valor do topo
  bool isEmpty(); //true se pilha estiver vazia

private:
  double *data;
  int topo;
  int maxsize;
};
#endif
