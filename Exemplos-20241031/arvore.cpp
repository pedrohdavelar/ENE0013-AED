#include "arvore.hpp"
#include <iostream>

//definicoes das funcoes-membro da classe Arvore

//construtor
Arvore::Arvore(std::string n1, std::string n2)
{
  nomeCientifico = n1;
  nome = n2;
}

//funcao-membro
std::string Arvore::meu_nome(int tipo)
{
  if(tipo == 0)
    return nomeCientifico;
  else
    if(tipo == 1)
      return nome;
    else
      return std::string("");
}
