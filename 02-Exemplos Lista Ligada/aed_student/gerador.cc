#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {

  int N = 10e2;
  std::ofstream outfile("notas.txt");
  std::string nomes[] = {"Ana", "Joao", "Tiburcio", "Maria"};

  for (size_t i = 0; i < N; i++) {
    outfile << nomes[rand()%4] << rand()%100;
    for (size_t j = 0; j < 8; j++) {
      outfile << " " << rand() % 101;
    }
    outfile << std::endl;
  }


  return 0;
}
