#include "conta.hpp"
#include <iostream>

using namespace std;

int main()
{
		int opcao;
		double saldo;

		cout << "Digite 1 para criar CC normal ou 2 para remunerada: ";
		cin >> opcao;

		while (opcao!=1 && opcao!=2){
			cout << endl << "Opcao invalida: digite 1 para criar CC normal ou 2 para remunerada: ";
			cin >> opcao;
		}

		//criacao do objeto apropriado --
		if(opcao == 1){ 
			contaCorrente contacorrente(10,100.0);
			saldo = contacorrente.saque(15.50); //sacando valor da conta
		}
		else
		{
			contaRemunerada contacorrente(10,1,100.0);
			saldo = contacorrente.aplicaRendimentos(1.05); //se estou lidando com obj ContaRemunerada, aplico rendimentos
		}

		cout << "Saldo: " << saldo << endl;//mostra o saldo

}
