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
    //metodo setter para o atributo matricula
    void setMatricula(int m){
      if(m>0)
        matricula = m;
      else
        matricula = 0;
    }
    //setter para o atributo media
    void setMedia(float m){
      media = m;
    }
    //metodo getter do atributo media
    float getMedia(){
      return media;
    }
};

//classe de objetos Turma e composta de array de objetos Ficha
//Exemplo de relacionamento de COMPOSICAO entre objetos 
class Turma{
  //atributos
  Ficha estudantes[100];
  int tamanho;

  public:
    //metodo que captura os dados de matricula e media dos alunos
    void preencheTurma(int quantidade){
      int matr;
      float nota;

      tamanho = quantidade;//atributo tamanho guarda numero de alunos

      if(quantidade<=100)
        for(int i=0;i<quantidade;i++){
          cout << "Digite a matricula do " << i+1 << "o aluno: ";
          cin >> matr;
          cout << "Digite a media do " << i+1 << "o aluno: ";
          cin >> nota;
          estudantes[i].setMatricula(matr);
          estudantes[i].setMedia(nota);
        }
    }
    //calcula media da turma
  	float mediaTurma(){
  		float resultado = 0;
  		for(int i=0; i < tamanho; i++)
  				resultado += estudantes[i].getMedia();
  		return resultado/tamanho;
  	}
};


int main (){

  Turma alunosRedes;
  int numeroAlunos;

  cout << "Quantos alunos tem a turma? ";
  cin >> numeroAlunos;
  alunosRedes.preencheTurma(numeroAlunos);
  cout << "Media global = " << alunosRedes.mediaTurma() << endl;


  return 0;
}
