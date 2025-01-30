#include <iostream>
#include <string>
#include <vector>

//Funções para a HEAPSEARCH feitas no EAC 10

void heapify(int v[], int p, int n){
int L, R, maior,swap;
L = (2*p) + 1; //eventual posicao do filho a esquerda 
R = (2*p) + 2; //eventual posicao do filho a direita

if ((L < n) && (v[L] > v[p])){maior = L;}else{maior = p;} //verifica se L < n para evitar overflow do array
if ((R < n) && (v[R] > v[maior])){maior = R;}             //verifica se R < n para evitar overflow do array

if (maior != p){
   swap=v[p];
   v[p]=v[maior];
   v[maior]=swap;
   heapify(v, maior, n);
   }
}

void build_heap(int v[], int n){
    for (int p = n/2;p >=0; p--){
        heapify(v, p, n);
    }
}

void heapsort(int v[], int n){
    int swap;
    build_heap(v,n);
    for (int p = n-1; p >=1; p--){
        swap = v[p];
        v[p] = v[0];
        v[0] = swap;
        heapify(v,0,--n);
    }
}

class nave{
    public:
    std::string nome;
    int qtdeTripulantes;
    int capacidadeCarga;
    int consumoPorHora;
}