#include <iostream>
#include <string>

bool palindromo(std::string palavra, int inicio, int fim){
    if (palavra.empty()){return true;}
    
    if (palavra.at(inicio) == palavra.at(fim)){
        if (inicio == fim){
            return true;
        } else if (fim - inicio == 1){
            return true;
        } else {
            inicio++;
            fim--;
            if (palindromo(palavra,inicio,fim)){return true;}else{return false;}
        }
    }
    return false;
}

std::string inverte(std::string s){
    if (s.empty()){return "";}
    
    std::string s_invertida;
    s_invertida = s.back();
    s.pop_back();
    if(!s.empty()){s_invertida += inverte(s);}
    return s_invertida;
}





int main(){

    std::string palavra = "";
    std::cin >> palavra;

    
    std::cout << "A palavra " << palavra << " eh um palindromo? "  << palindromo(palavra, 0, (palavra.size()-1)) << std::endl;
    std::cout << "A palavra invertida eh: " << inverte(palavra) << std::endl;
    return 0;
}