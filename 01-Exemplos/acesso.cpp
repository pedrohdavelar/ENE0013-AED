#include <iostream>
#include <string>

using namespace std;

class filme{
  private:
    double renda;
  public:
    int ano;
    string titulo;
    string ator;
    string atriz;

    //construtor padrao
    filme(){
      renda = 0;
      ano = -1;
      titulo = "";
      ator = "";
      atriz = "";
    }
    //construtor
    filme(double renda, int ano, string titulo, string ator, string atriz){
      this->renda = renda;// termo "this" significa o ponteiro para o proprio objeto do escopo
      this->ano = ano;
      this->titulo = titulo;
      this->ator = ator;
      this->atriz = atriz;
    }
    void imprimeInfo(){
      cout << titulo  << ", lancado em " << ano;
      cout << endl;
    }
    string elenco(){
      return ator + string(" e ") + atriz;
    }
    double getRenda(){//getter: acesso "somente leitura" a um atributo
      return renda;
    }
};


int main(int argc, char const *argv[]) {
  filme f(100000.0, 1989, "O silencio dos Inocentes", "Antony Hopkins", "Jodie Foster");

  f.imprimeInfo();

  cout << f.elenco() << " trabalharam juntos em " << f.ano << endl;

  //cout << "A renda foi " << f.renda << endl;//ERRO na compilacao, renda é privado!
  cout << "A renda foi " << f.getRenda() << endl;//solucao via chamada do metodo getter

  return 0;
}
