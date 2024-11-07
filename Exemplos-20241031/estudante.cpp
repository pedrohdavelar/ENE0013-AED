#include <iostream>


using namespace std;
//declaracao da classe
class Ficha {
  int matricula;
  float media;
public:
  Ficha(){ //construtor padrao - sem parametros
    matricula = 0;
    media = 0;
  }
  //imprime resultado do aluno
  void imprime(){
    cout  << "Aluno " << matricula
          << " tirou media " << media
          << endl;
  }
  //metodo setter - permite atualizacao de atributo privado
  //com validacao de dados, se necessario
  void setMatricula(int m){
    if(m>0)
      matricula = m;
    else
      matricula = 0;
  }
  void setMedia(float m){
    media = m;
  }
};


int main (){

  Ficha aluno1, aluno2;
  int matr;
  float nota;

  cout << "Digite a matricula do 1o aluno: ";
  cin >> matr;
  cout << "Digite a media do 1o aluno: ";
  cin >> nota;
  aluno1.setMatricula(matr);//ajusta matricula e nota do objeto aluno1
  //aluno1.media = nota; //ERRO DE COMPILACAO - media e atributo privado!
  aluno1.setMedia(nota); //solucao via invocacao do metodo setter

  cout << "Digite a matricula do 2o aluno: ";
  cin >> matr;
  cout << "Digite a media do 2o aluno: ";
  cin >> nota;
  aluno2.setMatricula(matr);//ajusta matricula e nota do objeto aluno2
  aluno2.setMedia(nota);


  aluno1.imprime();//imprime informacoes do objeto aluno1
  aluno2.imprime();//imprime informacoes do objeto aluno2


  return 0;
}
