#include <string>
#include <iostream>
using namespace std;

//declaracao da classe
class Arvore {
    public:
        string nome_c;
        string nome_p;     //Atributos Nome Científico e Nome Popular
        Arvore(string nc,string np){
            nome_c = nc;
            nome_p = np;
        }
         
        string meu_nome(int i) {
          switch (i) {
              case 0: return nome_c;
              case 1: return nome_p;
              default: return "";
          }
      }
};

// a small C++ program
#include <iostream>
using namespace std;
int main()
{
Arvore arv ("nomec", "nomep");
cout << "Nome cientifico: " << arv.meu_nome(0) << endl;
cout << "Nome popular   : " << arv.meu_nome(1) << endl;

return 0;
}

