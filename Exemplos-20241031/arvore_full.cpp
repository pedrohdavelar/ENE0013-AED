#include <string>
#include <iostream>

using namespace std;

//declaracao de uma classe
class Arvore{
    string nomeCientifico;
    string nome;

  public:
    //construtor
    /* este ="" significa que, se chamarem o construtor sem argumentos,
    os parametros vao receber o valor a direita, neste caso, "" (string vazia)*/
    Arvore(string n1 = "", string n2 = "")
    {
      nomeCientifico = n1;
      nome = n2;
    }

    //funcao-membro (metodo)
    string meu_nome(int tipo)
    {
      if(tipo == 0)
        return nomeCientifico;
      else
        if(tipo == 1)
          return nome;
        else
          return string("");
    }

};

//funcao principal do programa
int main(int argc, char const *argv[]) {

  //instanciando os objetos
  Arvore arv("Jacaranda acutifolia", "Jacaranda");
  Arvore arv2("Araucaria angustifolia", "Araucaria");
  Arvore arv3; //declara variavel sem argumentos - invoca construtor padrao

  //chamadas da funcao-membro dos objetos
  cout << "Meu nome cientifico e " << arv.meu_nome(0) << endl;
  cout << "Meu nome popular e " << arv2.meu_nome(1) << endl;
  cout << "Meu nome cientifico e " << arv3.meu_nome(0) << endl;

  return 0;
}
