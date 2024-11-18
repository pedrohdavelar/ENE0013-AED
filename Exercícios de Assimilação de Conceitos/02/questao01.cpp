//Questão 01 - EAC 02
#include<iostream>

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

int main(){
    retangulo ret (5.0,3.0);
    std::cout << "Altura : " << ret.getAltura() << std::endl;
    std::cout << "Largura: " << ret.getLado() << std::endl;
    std::cout << "Area   : " << ret.area() << std::endl;

    return 0;
}