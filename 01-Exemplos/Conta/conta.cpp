#include "conta.hpp"
#include <iostream>

using namespace std;

//construtor c/ 2 parametros
contaCorrente::contaCorrente(int numero, double saldo)
{
  this->numero = numero;
  this->saldo = saldo;
}

//obtem saldo da conta-corrente
double contaCorrente::getSaldo()
{
  return saldo;
}

//atualiza saldo da conta-corrente e o retorna a seguir
double contaCorrente::setSaldo(double novoSaldo)
{
  saldo = novoSaldo;
  return saldo;
}

int contaCorrente::getNumero()
{
  return numero;
}

//solicita saque de valor da CC
double contaCorrente::saque(double valor)
{
    if(valor < getSaldo())
      saldo = saldo - valor;
    else
      cout << "Saldo insuficiente!!" << endl;
    return getSaldo();
}

double contaCorrente::deposito(double valor)
{
  saldo = saldo + valor;
  return getSaldo();
}




//Classe contaRemunerada

//construtores identicos aos da superclasse - entao devem invoca-los na lista de inicializacao
contaRemunerada::contaRemunerada(int numero, int digito, double saldo) : contaCorrente(numero, saldo)
{
  this->digito = digito;
}


//metodo
double contaRemunerada::aplicaRendimentos(double taxa)
{
	double novosaldo;

	novosaldo = getSaldo();
	novosaldo *= taxa; //equivale a novosaldo = novosaldo * taxa;

	return setSaldo(novosaldo);
}
