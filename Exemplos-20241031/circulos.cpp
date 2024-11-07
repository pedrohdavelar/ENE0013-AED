
#include <iostream>
#include <string>

using namespace std;

class Circulo {
  public:
    //metodo que retorna uma string sobre o objeto
    string toString()
    {
		    return string("centro = 2,3; raio = 7");
    }
};


class CirculoBordado: public Circulo {

	//exemplo de sobrescrita (overriding) do metodo toString
	public:
    string toString()
    {
		    return Circulo::toString() + " Borda = 1";
    }
};

//programinha teste
int main() {

  Circulo oval;
  cout << oval.toString() << endl;

  CirculoBordado cir;
  cout << cir.toString() << endl;
}
