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

int main(){
    retangulo ret (5.0,3.0);
    std::cout << "Altura  ret: " << ret.getAltura() << std::endl;
    std::cout << "Largura ret: " << ret.getLado() << std::endl;
    std::cout << "Area    ret: " << ret.area() << std::endl;

    paralelepipedo pep;
    paralelepipedo pep2 (3.0,4.0,5.0);
    
    std::cout << "Altura  pep: " << pep.getAltura() << std::endl;
    std::cout << "Largura pep: " << pep.getLado() << std::endl;
    std::cout << "Area    pep: " << pep.area() << std::endl;
    std::cout << "Volume  pep: " << pep.volume() << std::endl;

    std::cout << "Altura  pep2: " << pep2.getAltura() << std::endl;
    std::cout << "Largura pep2: " << pep2.getLado() << std::endl;
    std::cout << "Area    pep2: " << pep2.area() << std::endl;
    std::cout << "Volume  pep2: " << pep2.volume() << std::endl;



    return 0;
}