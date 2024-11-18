#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// classe para ponto no plano 2D
class Ponto {
	//atributos
    protected:
		double x;
		double y;
    public:
		//construtores
		Ponto(){
            x=0.0;
            y=0.0;    
        }
        Ponto(double x, double y){
            	this->x = x;
	            this->y = y;
        }
		
		//metodo
		void mostraPonto(){
            	std::cout 	<< "Coordenadas : ("
				<< x
				<< ", "
				<< y
				<< ")"
				<< std::endl;
        }

        //setter
        void setPonto(double x, double y){
                this->x = x;
	            this->y = y;
        }
 
        //getters

        double getPontoX() {return x;}
        double getPontoY() {return y;}

};

class Curva {
    //atributos
    protected:
    std::vector<Ponto> Pontos;
    public:
    //construtores
    Curva(){}

    //metodos
    void inserePonto(double x, double y){
        Ponto p (x,y);
        Pontos.push_back(p);
    }

    double distUltPonto(int idx){
        double deltax , deltay = 0;
        if (Pontos.size() == 0 || Pontos.size() == 1 || (Pontos.size() - (idx+1) < 1)){ return 0.0;}
        else { 
            deltax = std::pow((Pontos[idx+1].getPontoX() - Pontos[idx].getPontoX()),2);
            deltay = std::pow((Pontos[idx+1].getPontoY() - Pontos[idx].getPontoY()),2);
            return std::sqrt(deltax + deltay);
            }
        } 
    
    
    double calcComp(){
        double comprimento = 0.0;
        for (unsigned int i = 0; i < Pontos.size(); i++){
            //std::cout << "itx: " << i << std::endl;
            //std::cout << "comprimento inicial: " << comprimento << std::endl;
            comprimento += distUltPonto(i);
            //std::cout << "Distancia entre os pontos " << i << " e " << i+1 << " :" << std::endl;
            //std::cout << "comprimento final: " << comprimento << std::endl;
            }
        return comprimento;
    }      
    
};

int main (){
    Curva c;
    double cordX, cordY = 0.0;
    /*c.inserePonto(0.0,0.0);
    c.inserePonto(2.0,2.0);
    std::cout << c.calcComp() << std::endl;
    */

    while (std::cin >> cordX >> cordY){
        c.inserePonto(cordX,cordY);
    }

    std::cout << std::fixed << std::setprecision(2) << c.calcComp() << std::endl;
    
    return 0;
}
