#include <iostream>
using namespace std;

//declaracao da classe Rectangle
class Rectangle {
  int width, height; //var. de instancia / atributos
  public:
    void set_values (int x, int y) { //metodo
      width = x;
      height = y;
    }
    int area () { //metodo
      return width*height;
    }
};

int main () {
  Rectangle rect, rectb; //criam-se dois objetos

  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  
  rect.set_values (3,4); //chamada do metodo para o objeto rect
  rectb.set_values (5,6); //chamada do metodo para o objeto rectb
  return 0;
}
