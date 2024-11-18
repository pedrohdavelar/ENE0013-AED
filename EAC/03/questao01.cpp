#include <iostream>
#include <string>

class Veiculo{
    protected:
    std::string nome, marca;                 //atributos
    int ano, potenciaCV;

    public:
    Veiculo(){                 //construtor padrao
        nome = " ";
        marca = " ";
        ano = 0;
        potenciaCV = 0;
    }

    Veiculo (std::string nome, std::string marca, int ano, int potenciaCV){ //construtor passando os 4 atributos
        this->nome=nome;
        this->marca=marca;
        this->ano=ano;
        this->potenciaCV=potenciaCV;
    }

    //getters

    std::string getInfo(){
        return ("Nome: " + nome + " - Marca: " + marca);
    }
};


class Caminhao: public Veiculo{
    private:
    int maxCarga, cargaAtual;         //novos atributos
    std::string tipoCarga;
    public:
    Caminhao() : Veiculo(){             //construtor padrao
        maxCarga=0;
        cargaAtual=0;
        tipoCarga=" ";
    }

    Caminhao(std::string nome, std::string marca, int ano, int potenciaCV, int maxCarga, std::string tipoCarga) : Veiculo(nome, marca, ano, potenciaCV){
        this->maxCarga=maxCarga;
        this->cargaAtual=0;
        this->tipoCarga=tipoCarga;
    }

    //getters

    std::string getInfoCarga(){
        return ("Tipo da carga: " + tipoCarga + " - Quantidade: " + std::to_string(cargaAtual) + "/" + std::to_string(maxCarga));
    }

    //setters
    int carrega(int qtde){
        cargaAtual += qtde;
        return cargaAtual;
    }

    int descarrega(){
        int qtde;
        qtde = cargaAtual;
        cargaAtual = 0;
        return qtde;
    }
};

int main (){
    Veiculo punto ("Fiat Punto", "Fiat", 2013, 117);
    Caminhao carreta ("Carretinha", "VW", 2020, 175, 200, "Carne");

    std::cout << punto.getInfo() << std::endl;

    std::cout << carreta.getInfo() << std::endl;
    std::cout << carreta.getInfoCarga() << std::endl;
    std::cout << "Carga atualizada: " << carreta.carrega(10) << std::endl;
    std::cout << carreta.getInfoCarga() << std::endl;
    std::cout << "Descarregando: " << carreta.descarrega() << std::endl;
    std::cout << carreta.getInfoCarga() << std::endl;
    
    return 0;
}