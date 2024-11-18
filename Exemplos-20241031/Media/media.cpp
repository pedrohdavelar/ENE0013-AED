#include <iostream>

class Calculadora{
    public:
        double media (int data[], int size){
            double soma = 0;
            for (size_t i = 0; i < size; i++)
            {
                soma += data[i];
            }
            return (soma/size); 
        }

        double media (double data[], int size){
            double soma = 0;
            for (size_t i = 0; i < size; i++)
            {
                soma += data[i];
            }
            return (soma/size); 
        }

        double media (float data[], int size){
            double soma = 0;
            for (size_t i = 0; i < size; i++)
            {
                soma += data[i];
            }
            return (soma/size); 
        }
};




int main (){

    Calculadora c;
    int tamanho, dadosI[128];
    double dadosD[128];
    float dadosF[128];
    
    char tipo;

    do
    {
        std::cout << "Digite 'i' para inteiro, 'd' para double, 'f' para float: ";
        std::cin >> tipo;
    } while (tipo != 'i' && tipo != 'd' && tipo != 'f');
    

    do {
    std::cout << "Quantos numeros deseja inserir (max 128): ";
    std::cin >> tamanho;
    } while (tamanho>128 || tamanho<0);

    
    switch (tipo)
    {
    case 'i':
        for (size_t i = 0; i < tamanho; i++){
            std::cout << "Digite o " << i+1 << "o numero: ";
            std::cin >> dadosI[i];
        }
        std::cout << "Media dos numeros: " << c.media(dadosI, tamanho) << std::endl;
        break;
    case 'd':
        for (size_t i = 0; i < tamanho; i++){
            std::cout << "Digite o " << i+1 << "o numero: ";
            std::cin >> dadosD[i];
        }
        std::cout << "Media dos numeros: " << c.media(dadosD, tamanho) << std::endl;
        break;
    case 'f':
        for (size_t i = 0; i < tamanho; i++){
            std::cout << "Digite o " << i+1 << "o numero: ";
            std::cin >> dadosF[i];
        }
        std::cout << "Media dos numeros: " << c.media(dadosF, tamanho) << std::endl;
        break;
    
    default:
        break;
    }

    
    

    return 0;
}