#include <iostream>
#include <string>
#include <vector>

class nave{
    public:                   //atributos
    std::string nome;
    int qtdeTripulantes;
    float capacidadeCarga;
    float consumoPorHora;
    int distanciaMaxima;

    //construtor
    nave(std::string nome, int qtdeTripulantes, float capacidadeCarga, float consumoPorHora, int distanciaMaxima){
        this->nome = nome;
        this->qtdeTripulantes = qtdeTripulantes;
        this->capacidadeCarga = capacidadeCarga;
        this->consumoPorHora = consumoPorHora;
        this->distanciaMaxima = distanciaMaxima;
    }

    void imprimeNave(){
        std::cout << nome << " " << qtdeTripulantes << " " << capacidadeCarga << " " << consumoPorHora << " " << distanciaMaxima << std::endl;
    }

//vejo duas maneiras de resolver o problema. Como há várias regras para a ordenação, poderia fazer diversos sorts para ordenar tudo...
//ou simplesmente fazer um overload do operador de comparação, embutindo todas as regras nesse overload, e aí simplesmente fazendo 
//um único sort para ordenar a frota. Acho a segunda opção bem mais simples, além de permitir usar os diversos tipos de sort ensinados nas aulas.
    bool operator<(const nave& n) const{
        if (qtdeTripulantes < n.qtdeTripulantes) {return true;}      //prioridade #1 - nr. tripulantes
        else if (qtdeTripulantes == n.qtdeTripulantes){
            if (capacidadeCarga < n.capacidadeCarga){return true;}   //prioridade #2 - capacidade de carga
            else if (capacidadeCarga == n.capacidadeCarga){
                if (consumoPorHora > n.consumoPorHora){return true;} //prioridade #3 - consumo por hora (menor consumo - maior prioridade)
                else if (consumoPorHora == n.consumoPorHora){
                    if (distanciaMaxima < n.distanciaMaxima){return true;} //prioridade #4 - distancia maxima
                    else if (distanciaMaxima == n.distanciaMaxima){
                        if (nome < n.nome) {return true;} //prioridade #5 - nome crescente
                    }
                }
            }
        } 
        return false;
    }
    bool operator>(const nave& n) const{
        if (qtdeTripulantes > n.qtdeTripulantes) {return true;}      //prioridade #1 - nr. tripulantes
        else if (qtdeTripulantes == n.qtdeTripulantes){
            if (capacidadeCarga > n.capacidadeCarga){return true;}   //prioridade #2 - capacidade de carga
            else if (capacidadeCarga == n.capacidadeCarga){
                if (consumoPorHora < n.consumoPorHora){return true;} //prioridade #3 - consumo por hora (menor consumo - maior prioridade)
                else if (consumoPorHora == n.consumoPorHora){
                    if (distanciaMaxima > n.distanciaMaxima){return true;} //prioridade #4 - distancia maxima
                    else if (distanciaMaxima == n.distanciaMaxima){
                        if (nome > n.nome) {return true;} //prioridade #5 - nome decrescente
                    }
                }
            }
        }
        return false;
    }
    bool operator==(const nave& n) const{
        return (qtdeTripulantes == n.qtdeTripulantes && capacidadeCarga == n.capacidadeCarga && consumoPorHora == n.consumoPorHora && distanciaMaxima == n.distanciaMaxima && nome == n.nome);
    }
    bool operator<=(const nave& n) const{
        return (*this < n || *this == n);
    }
    bool operator>=(const nave& n) const{
        return (*this > n || *this == n);
    } 
};

std::vector<nave> frota;

void imprimeFrota(){
    for (int i = 0; i < frota.size(); i++){
        frota[i].imprimeNave();
    }
}


//Funções para a HEAPSEARCH feitas no EAC 10

void heapify(std::vector<nave>& frota, int p){
    int n = frota.size();
    int L, R, maior;
    nave swap;
    L = (2*p) + 1; //eventual posicao do filho a esquerda 
    R = (2*p) + 2; //eventual posicao do filho a direita

    if ((L < n) && (frota[L] > frota[p])){maior = L;}else{maior = p;} //verifica se L < n para evitar overflow do array
    if ((R < n) && (frota[R] > frota[maior])){maior = R;}             //verifica se R < n para evitar overflow do array

    if (maior != p){
       swap=frota[p];
       frota[p]=frota[maior];
       frota[maior]=swap;
       heapify(frota, maior);
       }
}

void build_heap(std::vector<nave>& frota){
    int n = frota.size();
    for (int p = n/2;p >=0; p--){
        heapify(frota, p);
    }
}

void heapsort(std::vector<nave>& frota){
    int n = frota.size();
    nave swap;
    build_heap(frota);
    for (int p = n-1; p >=1; p--){
        swap = frota[p];
        frota[p] = frota[0];
        frota[0] = swap;
        heapify(frota,0);
    }
}

int main (){
    nave input;
    frota naves;
    while(true){
        std::cin >> input.nome >> input.qtdeTripulantes >> input.capacidadeCarga >> input.consumoPorHora >> input.distanciaMaxima;
        frota.push_back(input);
    }
    imprimeFrota();
    return 0;
}