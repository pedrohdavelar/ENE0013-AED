#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <queue>
#include <iostream>

template<class T>
class BSTNode {
public:
    //CONSTRUTORES
    BSTNode() {
        left = right = 0;
    }
    BSTNode(const T& el, BSTNode<T> *left = 0, BSTNode<T> *right = 0) {
        this->el = el;
        this->left = left;
        this->right = right;
    }

    //ATRIBUTOS
    T el; //elemento a se armazenar
    BSTNode<T> *left, *right; //apontadores para subarvore esquerda e direita
};


template<class T>
class BST {
public:
    BST() {
        root = 0;
    }

    ~BST() {
      clear(root);
      root = 0;
    }

    bool isEmpty() const {
        return root == 0;
    }

    void inorder() {
        inorder(root);
    }

    void insert(const T&);

    T* search(const T& el) const {
        return search(root,el); //opcao nao-recursiva
    }

    void breadthFirst();

protected:
    BSTNode<T>* root; //raiz da arvore

    //metodos protegidos (protected)
    void clear(BSTNode<T>*);
    T* search(BSTNode<T>*, const T&) const;
    void inorder(BSTNode<T>*);
    void visit(BSTNode<T>* p) {
        std::cout << p->el << ' ';
    }
};//FIM CLASSE BST

template<class T>
void BST<T>::clear(BSTNode<T> *p) {
    if (p != 0) {
         clear(p->left);
         clear(p->right);
         delete p;
     }
}

template<class T>
void BST<T>::insert(const T& el) {
  BSTNode<T> *p, *parent;
  p=root; //inicia na raiz
  parent = 0;
  while (p != 0){ //pesquisa pelo ponto de insercao
    parent = p;
    if (el < p->el)
      p = p->left;
    else
      p = p->right;
  }
  if(root == 0)
    root = new BSTNode<T>(el);
  else
    if(el < parent->el)
      parent->left = new BSTNode<T>(el);
    else
      parent->right = new BSTNode<T>(el);
}

template<class T>
T* BST<T>::search(BSTNode<T>* p, const T& el) const {
  while (p != 0)
    if (el == p->el)
      return &p->el;
    else
      if (el < p->el)
        p = p->left;
      else
        p = p->right;
  return 0;
}

template<class T>
void BST<T>::inorder(BSTNode<T> *p) {
     if (p != 0) {
         inorder(p->left);
         visit(p);
         inorder(p->right);
     }
}

template<class T>
void BST<T>::breadthFirst() {
    std::queue< BSTNode<T>* > fila;
    BSTNode<T> *p = root;
    if (p != 0) {
        fila.push(p);
        while (!fila.empty()) {
            p = fila.front(); //pega no do inicio da fila
            fila.pop(); //remove no do inicio da fila
            visit(p);
            if (p->left != 0)
                 fila.push(p->left); //insere no final da fila
            if (p->right != 0)
                 fila.push(p->right); //insere no final da fila
        }
    }
}
#endif
