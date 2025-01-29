#include "busca.h"

int buscabinaria(int* v, int n, int value)
{
  int inicio, fim, pos;

  inicio = 0;
  fim = n-1;

  while (inicio <= fim)
  {
        pos = (inicio+fim)/2;
        if (value < v[pos])
           fim = pos-1; //value esta na 1a metade
        else
            if (value > v[pos])
               inicio = pos + 1; //value esta na 2a metade
            else
               return pos; //achou: value == v[pos]
  }
  return -1; //nao achou
}

int buscabinariarecursiva(int* v, int inicio, int fim, int value)
{
  if(inicio > fim)
    return -1; //caso base - nao achou
  else
  {
    int pos = (inicio+fim)/2;
    if (value < v[pos])
        return buscabinariarecursiva(v, inicio, pos-1, value); //value esta na 1a metade
    else
        if (value > v[pos])
           return buscabinariarecursiva(v, pos + 1, fim, value); //value esta na 2a metade
        else
           return pos; //achou: value == v[pos]
  }
}

//Procura value em um array de inteiros - busca linear.
int buscalinear(int *v, int n, int value)
{
  int i;
  for(i = 0; i < n; i++){
    if (v[i] == value)
      return i;
  }
  return -1; //nao achou
}
