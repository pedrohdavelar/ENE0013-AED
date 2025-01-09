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

    void preorder() {
        preorder(root);
    }

    void inorder() {
        inorder(root);
    }

    void postorder() {
        postorder(root);
    }

    void insert(const T&);

    T* search(const T& el) const {
        return recursiveSearch(root,el);
        // return search(root,el); //opcao nao-recursiva
    }

    void breadthFirst();

protected:
    BSTNode<T>* root; //raiz da arvore

    //metodos protegidos (protected)
    void clear(BSTNode<T>*);
    T* search(BSTNode<T>*, const T&) const;
    T* recursiveSearch(BSTNode<T>*, const T&) const;
    void preorder(BSTNode<T>*);
    void inorder(BSTNode<T>*);
    void postorder(BSTNode<T>*);
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
  BSTNode<T> *p = root, *prev = 0;
  while (p != 0) {  // find a place for inserting new node;
    prev = p;
    if (el < p->el)
      p = p->left;
    else
      p = p->right;
  }
  if (root == 0)    // tree is empty;
    root = new BSTNode<T>(el);
  else
    if (el < prev->el)
      prev->left  = new BSTNode<T>(el);
    else
      prev->right = new BSTNode<T>(el);
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
T* BST<T>::recursiveSearch(BSTNode<T>* p, const T& el) const {
  if (p != 0){
    if (el == p->el){
        return &p->el;
        } 
    else if (el < p->el){
        return recursiveSearch(p->left,el);
        }
    else{
        return recursiveSearch(p->right,el);
        }
  } 
  else {
    return 0;
  }
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
void BST<T>::preorder(BSTNode<T> *p) {
    //COMPLETE O CODIGO
    if (p != 0){
        visit(p);
        if (p->left != 0){preorder(p->left);}
        if (p->right != 0){preorder(p->right);}
    }
}

template<class T>
void BST<T>::postorder(BSTNode<T>* p) {
    //COMPLETE O CODIGO
    if (p != 0){
        if (p->left != 0){postorder(p->left);}
        if (p->right != 0){postorder(p->right);}
        visit(p);
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

int main (){
    int input = 0;
    
    BST<int> arvore;

    std::cin >> input;

    while(input >=  0){
        arvore.insert(input);
        std::cin >> input;
    }

    
    std::cout << "Digite o inteiro a buscar, negativo para parar:" << std::endl;
    std::cin >> input;

    while(input >=  0){
        if (arvore.search(input) != 0){
            std::cout << "Valor " << input << " encontrado!" << std::endl;
        }
        else {
            std::cout << "Valor não encontrado." << std::endl;
        }
        std::cout << "Digite o inteiro a buscar, negativo para parar:" << std::endl;
        std::cin >> input;
    }
    return 0;
}