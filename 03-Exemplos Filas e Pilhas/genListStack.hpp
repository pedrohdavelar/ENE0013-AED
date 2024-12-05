//**********************  genListStack.hpp  *************************
//     generic stack defined as a doubly linked list

#ifndef LL_STACK
#define LL_STACK

#include <list>

//classes genericas sao declaradas E DEFINIDAS no arquivo .hpp

template<class T> //tipo generico T definido
class LLStack {
public:
    LLStack() {
    }

    void clear() {
        lst.clear(); //apaga elementos da lista
    }

    bool isEmpty() {
        return lst.empty();
    }

    T& peek() {
        return lst.back(); //retorna valor do topo (final) da lista
    }

    T pop() {
        T el = lst.back(); //pega valor do topo (final)
        lst.pop_back(); // remove valor
        return el;
    }

    void push(const T& el) {
        lst.push_back(el); //armazena novo elemento no topo (final)
    }

private:
    std::list<T> lst; //o objeto lista que guarda os elementos da pilha fica privado
};

#endif
