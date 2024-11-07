#ifndef GUARD_conta
#define GUARD_conta


class contaCorrente{
private:
  int numero;
  double saldo;

public:
  //construtor
  contaCorrente(int num, double valor = 0.0);

  //obtem saldo da conta-corrente
  double getSaldo();

  double setSaldo(double novosaldo);

  //obtem numero da CC
  int getNumero();

  //solicita saque de valor da CC
  double saque(double valor);

  //deposita valor na CC
  double deposito(double valor);
};

class contaRemunerada : public contaCorrente {
private:
  int digito;
public:
	//construtores
	contaRemunerada(int numero, int digito, double saldo = 0.0);

	//metodo
	double aplicaRendimentos(double taxa);

};


#endif
