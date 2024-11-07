#ifndef GUARD_arvore
#define GUARD_arvore

//arvore.hpp - arquivo de declaracoes da classe Arvore
#include <string>

//classe
class Arvore{
  private:
    //atributos privados
    std::string nomeCientifico;
    std::string nome;

  public:
    //construtor - valor padrao para os parametros eh string vazia
    Arvore(std::string n1 = "", std::string n2 = "");
    //funcao-membro (metodo)
    std::string meu_nome(int tipo);
};
#endif
