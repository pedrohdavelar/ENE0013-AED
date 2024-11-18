#include<iostream>
#include<string>
//declaracao da classe
class Arvore {
    public:
        std::string nome_c;
        std::string nome_p;     //Atributos Nome Científico e Nome Popular
        Arvore(std::string nc,std::string np){
            nome_c = nc;
            nome_p = np;
        }
         
        std::string meu_nome(int i) {
          switch (i) {
              case 0: return nome_c;
              case 1: return nome_p;
              default: return "";
          }
      }
};

int main(){
    Arvore arv("Nome cientifico","Nome popular");
    std::cout << "O nome cientifico da arvore eh: " << arv.meu_nome(0) << std::endl;
    std::cout << "O nome popular da arvore eh: " << arv.meu_nome(1) << std::endl;

    return 0;
}