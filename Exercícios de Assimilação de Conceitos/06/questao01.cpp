#include <iostream>
#include <stack>

int main(){

    int n,b;
    std::stack<int> resposta;

    while(std::cin >> n >> b){
        if(n<0){break;}            //n<0 -> sai do loop 
        
        if(n==0){std::cout << 0;} 
        
        while (n>0){
        resposta.push(n%b);
        //std::cout << "n: " << n << " b: " << b << " n%b: " << n%b << std::endl; 
        n/=b;
        }

        while(!resposta.empty()){
            std::cout << resposta.top();
            resposta.pop();
        }
        std::cout << std::endl;
    };

    return 0;
} 
