#include <iostream>
using namespace std;

//declaracao da classe Rectangle
class Rectangle {
  int width, height; //var. de instancia / atributos
  public:
    Rectangle(int x, int y) { //construtor da classe
      width = x;
      height = y;
    }
    int area () { //metodo
      return width*height;
    }
};

int main () {
  //criam-se dois objetos, informando os parametros do construtor
  Rectangle rect(3,4), rectb(5,6);
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  return 0;
}
