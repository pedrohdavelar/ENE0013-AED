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
            dados = novos_dados;                            //desalocamos a antiga pilha
            delete[] dados;                      //dados ira apontar para a nova pilha
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

        int capacidadePilha(){return capacidade;}      //quantos elementos a pilha pode armazenar
        
        void imprimePilha(std::string com_espaco = "n"){
            if (estaVazia()){std::cout << "Pilha Vazia";}
            else{
                for (int i = topo; i >=0; i--){      //Como é uma pilha, a iteração deve ser em ordem decrescente
                    std::cout << dados[i];
                    if(com_espaco == "s" || com_espaco == "S"){std::cout << " ";} //para facilitar o reuso deste código
                }                                                                 //ja que para o exercicio será necessario
            }                                                                     //imprimir os elementos sem espaço mas
        }                                                                         //o normal é imprimir com espaço...

};


int main (){

    std::string numero1,numero2,pivot;                    //string para os numeros 1 e 2, pivot para receber cada caractere
    std::cin >> numero1 >> numero2;                       //le os dois numeros/strings
    
    int digito1 = 0, tamanho1 = 0;                        //digito dos numeros 1 e 2, tamanho das pilhas 1 e 2 
    int digito2 = 0, tamanho2 = 0;
    int digito_resposta = 0, tamanho_resposta = 0;        //digito da resposta, tamanho da resposta
    int vai_um = 0;                                       //vai um
  
    tamanho1 = numero1.size();
    Pilha<int> pilha1(tamanho1);
    tamanho2 = numero2.size();
    Pilha<int> pilha2(tamanho2);
 
    if (!numero1.empty()){                                   //Converte os digitos da string em int e 
        for (int i = numero1.size(); i > 0; i--){            //insere na pilha
            pivot = numero1.front();                         //jogando n1.back() direto na std::stoi() deu erro, então criei essa
            digito1 = std::stoi(pivot);                      //string "pivot" para receber o digito e fazer a conversão para int
            numero1.erase(0,1);
            pilha1.insereElemento(digito1);
        } 
    }

    if (!numero2.empty()){
        for (int i = numero2.size(); i > 0; i--){
            pivot = numero2.front();
            digito2 = std::stoi(pivot);
            numero2.erase(0,1);
            pilha2.insereElemento(digito2);
        } 
    }
    
    if(tamanho1 > tamanho2){                           //para evitar operaçoes de redimensionamento desnecessárias, 
        tamanho_resposta = tamanho1;                   //montamos a pilha para a resposta com o tamanho do maior 
    }else{                                             //numero inserido.
        tamanho_resposta = tamanho2;
    }

    tamanho_resposta++;
    
    Pilha<int> pilha_resposta(tamanho_resposta);

    while(tamanho_resposta > 0){
        digito1 = digito2 = digito_resposta = 0;                             //inicialização das variaveis a cada iteração

        if (!pilha1.estaVazia()){                                            //extrai o digito de p1
            digito1 = pilha1.observaTopo();
            pilha1.removeElemento();
        }

        if (!pilha2.estaVazia()){                                            //extrai o digito de p2
            digito2 = pilha2.observaTopo();
            pilha2.removeElemento();
        }
        //std::cout << digito1 << " + " << digito2 << " + " << vai_um << std::endl;
        digito_resposta = digito1 + digito2 + vai_um;                  //soma os digitos de cada uma das pilhas e o vai um da ultima soma
        //std::cout << digito_resposta << " " << (digito_resposta%10) << std::endl;
        vai_um = 0;
        if (digito_resposta >= 10){                                    //se r for maior ou igual a dez então pegamos o resto de sua divisão por 10
            digito_resposta %= 10;                                     //para extrair o ultimo digito e atribuimos 1 ao vai 1; senão então zeramos
            vai_um = 1;                                                //o vai 1 para a proxima iteração
        }                   
        
        pilha_resposta.insereElemento(digito_resposta);          //por fim inserimos o digito obtido na resposta;
        //std::cout << "Resposta no momento: ";
        //pilha_resposta.imprimePilha("s");
        //std::cout << std::endl;
        tamanho_resposta--;
    }

    if (vai_um == 1){pilha_resposta.insereElemento(vai_um);}  //se ao terminar de iterar as duas pilhas sobrar um vai 1, então devemos adicionar 
                                                              //este ultimo dígito a resposta
    pilha_resposta.imprimePilha();
    std::cout << std::endl;
    return 0;
}