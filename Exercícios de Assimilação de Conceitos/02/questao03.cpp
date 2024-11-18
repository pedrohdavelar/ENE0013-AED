#include <iostream>
#include <iomanip>

class retangulo{
  protected:
  double lado, altura; //var. de instancia / atributos
  public:
    //construtores
    retangulo(){
        lado=0.0;
        altura=0.0;
    }
    
    retangulo(double lado, double altura){
        this->lado=lado;
        this->altura=altura;
    }

    //getters
    double getLado(){
        return lado;
    } 
    double getAltura(){
        return altura;
    }

    //setters
    void setLado(double novo_lado){
        lado = novo_lado;
    }
    void setAltura(double novo_altura){
        altura=novo_altura;
    }

    double area(){
        return lado*altura;
    } 
};

class paralelepipedo: public retangulo{
    private:
    //novo atributo
    double profundidade;
    public:
    //construtor
    paralelepipedo() : retangulo(){
        profundidade=0.0;
    }
    paralelepipedo(double lado, double altura, double profundidade) : retangulo(lado, altura){
        this->profundidade=profundidade;
    }
    //novo getter
    double getProfundidade(){
        return profundidade;
    }
    //novo setter
    void setProfundidade(double novo_profundidade){
        profundidade=novo_profundidade;
    }
    double volume()
    {
        return lado*altura*profundidade;
    }
};
    
int main (){
    char opcao;
    double x,y,z; //lado,altura,profundidade
    std::cout << "Qual geometria? (r=retangulo, p=paralelepipedo)" << std::endl;
    std::cin >> opcao;

    switch(opcao){
        case 'r':{
            std::cout << "Digite a largura: ";
            std::cin >> x;
            std::cout << "Digite a altura: ";
            std::cin >> y;
            retangulo ret(x,y);
            std::cout << "A area do seu retangulo eh: ";
            std::cout << std::fixed << std::setprecision(2) << ret.area() << std::endl;
            break;
        }
        case 'p':{
            std::cout << "Digite a largura: ";
            std::cin >> x;
            std::cout << "Digite a altura: ";
            std::cin >> y;
            std::cout << "Digite a profundidade: ";
            std::cin >> z;
            paralelepipedo pep(x,y,z);
            std::cout << "O volume do seu retangulo eh: ";
            std::cout << std::fixed << std::setprecision(2) <<pep.volume() << std::endl;
            break;
        }
        default:
            std::cout << "ESCOLHA ERRADA!";
    }


    
    return 0;
}    
    
 
