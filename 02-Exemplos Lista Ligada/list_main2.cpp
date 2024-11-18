#include "list.hpp"
#include <iostream>

int main(int argc, char const *argv[]){

    linkedList lista;
    int valor;

    std::cout << "Digite os valores a adicionar a lista:" << std::endl;
    std::cin >> valor;
    while(valor > 0){    //leitura de inteiros enquanto não digitar ctrl+d
        lista.addHead(valor);
        std::cin >> valor;
    }



std::cout << "Insira um inteiro para pesquisar: ";
std::cin >> valor;

if(lista.inList(valor)){
    std::cout << "Valor encontrado!" << std::endl;
}
else {
    std::cout << "Valor nao encontrado!" << std::endl;
}

return 0;
}