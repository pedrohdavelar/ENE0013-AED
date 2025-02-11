#include <iostream>
#include <string>
#include <vector>


//classe para guardar os atributos definidos no enunciado da  tarefa
class nave{
    public:                   //atributos
    std::string nome;
    int qtdeTripulantes;
    float capacidadeCarga;
    float consumoPorHora;
    int distanciaMaxima;

    //construtor padrão
    nave() : nome(""), qtdeTripulantes(0), capacidadeCarga(0.0), consumoPorHora(0.0), distanciaMaxima(0) {}
    //construtor parametrizado
    nave(std::string nome, int qtdeTripulantes, float capacidadeCarga, float consumoPorHora, int distanciaMaxima)
        : nome(nome), qtdeTripulantes(qtdeTripulantes), capacidadeCarga(capacidadeCarga), consumoPorHora(consumoPorHora), distanciaMaxima(distanciaMaxima) {}

    void imprimeNave(){
        std::cout << nome << " " << qtdeTripulantes << " " << capacidadeCarga << " " << consumoPorHora << " " << distanciaMaxima << std::endl;
    }
    void imprimeNome(){
        std::cout << nome << std::endl;
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
                        if (nome > n.nome) {return true;} //prioridade #5 - nome crescente
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
                        if (nome < n.nome) {return true;} //prioridade #5 - nome decrescente
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

//frota poderia ser uma classe, mas como o tempo está corrido foi mais prático fazer um vector global.
std::vector<nave> frota;
//do mesmo jeito que essas funções poderiam ser métodos de uma classe frota, mas tá corrido...
//imprimeFrota foi usado mais para testes
void imprimeFrota(){
    for (int i = 0; i < frota.size(); i++){
        frota[i].imprimeNave();
    }
}

//a ideia era usar o heapsearch do EAC 10, mas o tempo tá corrido. O bubblesort é mais simples. Seria mais legal também usar
//Template, mas novamente, o tempo tá corrido....
void bubbleSort(std::vector<nave>& frota){
    int n = frota.size();
    nave swap;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (frota[j] < frota[j+1]){     //lógica invertida porque as naves de maior prioridade serão as escolhidas para as missões (maior prioridade -> maior índice)
                swap = frota[j];
                frota[j] = frota[j+1];
                frota[j+1] = swap;
            }
        }
    }
}

int main (){
    int casosTeste = 0, totalNaves = 0, selNaves = 0;
    nave input; //objeto para receber as entradas e adicionar ao vector do objeto <nave> frota
    
    std::vector<std::string> textOutput; //como a saída deve ser impressa após a inserção de todos os dados, para facilitar a logica,
    //durante a execução a cada missão salva a saída nesse vector e depois itero ele para imprimir tudo
    
    while (casosTeste <= 0){                  //a quantidade de casos de teste vai definir a qtde de iterações do loop principal. Cada iteração = 1 missão
        //std::cout << "Qtde casos teste: ";
        std::cin  >> casosTeste;
    }
    
    for (int numeroMissao = 1; numeroMissao <= casosTeste; numeroMissao++){ 

        //limpa a frota, a qtde de naves e a qtde selecionada de naves a cada iteração
        frota.clear();
        totalNaves = 0;
        selNaves = 0;
        //std::cout << "Missao " << numeroMissao << std::endl;
        //std::cout << "totalNaves: " << totalNaves << " selNaves: " << selNaves << std::endl;
        while (totalNaves <= 0){        //garante que o numero de naves seja um numero positivo
            //std::cout << "Qtde naves: ";
            std::cin >> totalNaves;
        }

        while (selNaves <= 0 || selNaves > totalNaves){ //garante que o numero de naves selecionadas seja um numero positivo e menor que o total de naves
            //std::cout << "Qtde Naves selecionadas: ";
            std::cin >> selNaves;
        } 
        //leitura do numero de naves especificado. O programa não especifica um caso de erro então vou assumir que todas as entradas serão válidas
        for (int i = 0; i < totalNaves; i++){   
            //std::cout << "i: " << i << "/ totalNaves: : " << totalNaves << std::endl;
            //std::cout << "Parametros de entrada: " << std::endl;
            //std::cout << "Nome (string), qtdeTripulantes (int), capacidadeCarga(float), consumoPorHora(float), distanciaMaxima(int)" << std::endl;
            std::cin >> input.nome >> input.qtdeTripulantes >> input.capacidadeCarga >> input.consumoPorHora >> input.distanciaMaxima;
            frota.push_back(input);
        }

        //std::cout << "Frota pré sort: ";
        //imprimeFrota(); std::cout << std::endl;
        //ordenamento da frota via bubbleSort;
        bubbleSort(frota);
        //std::cout << "Frota pós sort: ";
        //imprimeFrota(); std::cout << std::endl;
        //imprimeFrota();
        //saída formatada cfe exemplo
        
        //ao inves de imprimir para o console, cada linha é salva no vector textOutput. Dessa forma é possível atender a formatação 
        //experada do enunciado.
        textOutput.push_back("MISSAO " + std::to_string(numeroMissao));
        for (int i = 0; i < selNaves; i++){
            textOutput.push_back(std::to_string(i+1) + " " + frota[i].nome);
        }
    }
    //apos processar todas as missões, iterar o vector textOutput para imprimir no console a saída
    for (int i = 0; i < textOutput.size(); i++){
        std::cout << textOutput[i] << std::endl;
    }
    return 0;
}