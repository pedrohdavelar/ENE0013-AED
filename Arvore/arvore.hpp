#include <string>

class Arvore{
    std::string nomeCientifico;
    std::string nome;

    public:
    //construtor
    /* este ="" significa que, se chamarem o construtor sem argumentos,
    os parametros vao receber o valor a direita, neste caso, "" (string vazia)*/
    Arvore(std::string n1 = "", std::string n2 = "");
    std::string meu_nome(int tipo);
};