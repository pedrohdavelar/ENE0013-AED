#include <iostream>
#include <string>
#include <exception>

//Classe Pilha

template<class T>
class Pilha {
    private:                     //Atributos
        T* dados;
        int topo;
        int capacidade;

    public:
        Pilha(int capacidade_inicial = 15){     //Construtor
            capacidade = capacidade_inicial;    
            dados = new T[capacidade];          //alocação dinâmica com tamanho padrão 15
            topo = -1;                          //No caso da pilha vazia, o topo é -1;
        }                                       //com 1 item o índice sera 0

        ~Pilha() {                              //Destrutor
            delete[] dados; 
        }
                                                //Métodos
        bool estaVazia(){
            return (topo == -1);                //Topo == -1 significa que a pilha não tem elementos
        }

        bool estaCheia(){
            return (topo == (capacidade - 1));  //Indices começam em zero logo o ultimo item possivel será
        }                                       //no índice (capacidade - 1)

        void redimensionarPilha(){
            int nova_capacidade = capacidade * 2;      //Dobramos o tamanho da pilha
            T* novos_dados = new T[nova_capacidade];   //Alocamos a memoria para os dados

            for (size_t i; i<topo; i++){               //iteramos a pilha atual repassando os dados
                novos_dados[i] = dados[i];             //para a nova area de memoria
            }
            delete[] dados;                            //desalocamos a antiga pilha
            dados = novos_dados;                       //dados ira apontar para a nova pilha
            capacidade = nova_capacidade;              //e a capacidade agora é dobrada
        }

        void insereElemento (T elemento){              //vulgo push
            if (estaCheia()){redimensionarPilha();}    //lista cheia? arruma mais espaço
            topo++;                                    //incrementamos o indice porque
            dados[topo] = elemento;                    //em uma pilha sempre inserimos E retiramos
        }                                              //o elemento no topo

        void removeElemento(){                         //vulgo pop
            if (estaVazia()){return;}                  //lista vazia? não faz nada
            topo--;                                    //Nao interessa se vai ficar dados no elemento acima, ele
        }                                              //só voltará a ser referenciado se inserimos novo elemento

        T observaTopo(){
            if(estaVazia()){throw std::underflow_error("Erro:lista vazia");} //Por estar usando template, foi necessário usar uma exceção...
            return dados[topo];                        //Retorna o valor do elemento do topo da lista
        }

        int tamanhoPilha(){return (topo + 1);}         //Como o indice começa em zero, a qtde sera topo + 1

        void imprimePilha(std::string com_espaco = "n"){
            if (estaVazia()){std::cout << "Pilha Vazia";}
            else{
                for (size_t i = topo; i >=0; i--){      //Como é uma pilha, a iteração deve ser em ordem decrescente
                    std::cout << dados[i];
                    if(com_espaco == "s" || com_espaco == "S"){std::cout << " ";} //para facilitar o reuso deste código
                }                                                                 //ja que para o exercicio será necessario
            }                                                                     //imprimir os elementos sem espaço mas
        }                                                                         //o normal é imprimir com espaço...

};




int main (){

    std::string n1,n2;
    std::cin >> n1,n2;
    int d1 = 0, d2 = 0, vai1 = 0, r = 0, tamanho_resposta = 0;
    d1 = d2 = vai1 = r = 0;

    
    
    Pilha<int> p1(n1.size());
    Pilha<int> p2(n2.size());
    
    if (!n1.empty()){
        for (size_t i = n1.size(); i > 0; i--){
            d1 = std::stoi(n1.back());
            n1.pop_back();
            p1.insereElemento(d1);
        } 
    }

    if (!n2.empty()){
        for (size_t i = n2.size(); i > 0; i--){
            d2 = std::stoi(n2.back());
            n2.pop_back();
            p2.insereElemento(d2);
        } 
    }
    
    if(n1.size()>n2.size()){tamanho_resposta = (n1.size()+1);}
    else{tamanho_resposta = (n2.size()+1);}
    Pilha<size_t> resposta(tamanho_resposta);

    while(!p1.estaVazia() && p2.estaVazia()){
        d1 = d2 = vai1 = r = 0;                                        //inicialização das variaveis a cada iteração

        if (!p1.estaVazia){                                            //extrai o digito de p1

        }

    } 

    return 0;


}
