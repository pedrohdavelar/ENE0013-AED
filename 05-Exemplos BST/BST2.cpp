#include <queue>
#include <stack>
#include <iostream>
#include <string>


template<class T>
class BSTNode {
public:
    BSTNode() {
        left = right = 0;
    }
    BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
        el = e; left = l; right = r;
    }
    T el;
    BSTNode<T> *left, *right;
};

template<class T>
class BST {
public:
    BST() {
        root = 0;
    }
    ~BST() {
        clear();
    }
    void clear() {
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
        return search(root,el);
        // return recursiveSearch(root,el);
    }

    void findAndDeleteByCopying(const T&);
    void findAndDeleteByMerging(const T&);
    void breadthFirst();

protected:
    BSTNode<T>* root;
    void clear(BSTNode<T>*);
    void recursiveInsert(BSTNode<T>*&, const T&);
    T* search(BSTNode<T>*, const T&) const;
    T* recursiveSearch(BSTNode<T>*, const T&) const;
    void preorder(BSTNode<T>*);
    void inorder(BSTNode<T>*);
    void postorder(BSTNode<T>*);
    void visit(BSTNode<T>* p) {
        std::cout << p->el << ' ';
    }
    void deleteByCopying(BSTNode<T>*&);
    void deleteByMerging(BSTNode<T>*&);
};

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
        else p = p->right;
    }
    if (root == 0)    // tree is empty;
         root = new BSTNode<T>(el);
    else if (el < prev->el)
         prev->left  = new BSTNode<T>(el);
    else prev->right = new BSTNode<T>(el);
}

template<class T>
T* BST<T>::search(BSTNode<T>* p, const T& el) const {
    while (p != 0)
        if (el == p->el)
             return &p->el;
        else if (el < p->el)
             p = p->left;
        else p = p->right;
    return 0;
}

template<class T>
T* BST<T>::recursiveSearch(BSTNode<T>* p, const T& el) const {
    if (p != 0)
         if (el == p->el)
              return &p->el;
         else if (el < p->el)
              return recursiveSearch(p->left,el);
         else return recursiveSearch(p->right,el);
    else return 0;
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
    if (p != 0) {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template<class T>
void BST<T>::postorder(BSTNode<T>* p) {
    if (p != 0) {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

template<class T>
void BST<T>::deleteByCopying(BSTNode<T>*& node) {
  BSTNode<T> *previous, *tmp = node;
  if (node->right == 0)                  // node has no right child;
    node = node->left;
  else
    if (node->left == 0)              // node has no left child;
      node = node->right;
    else {
      tmp = node->left;                  // node has both children;
      previous = node;                  // 1.
      while (tmp->right != 0) {         // 2.
        previous = tmp;
        tmp = tmp->right;
      }
      node->el = tmp->el;               // 3.
      if (previous == node)
        previous->left  = tmp->left;
      else
        previous->right = tmp->left; // 4.
    }
  delete tmp;                            // 5.
}

// findAndDeleteByCopying() searches the tree to locate the node containing
// el. If the node is located, the function DeleteByCopying() is called.

template<class T>
void BST<T>::findAndDeleteByCopying(const T& el) {
  BSTNode<T> *p = root, *prev = 0;
  while (p != 0 && !(p->el == el)) {
    prev = p;
    if (el < p->el)
      p = p->left;
    else
      p = p->right;
  }
  if (p != 0 && p->el == el)
    if (p == root)
      deleteByCopying(root);
    else
      if (prev->left == p)
        deleteByCopying(prev->left);
      else
        deleteByCopying(prev->right);
  else
    if (root != 0)
      std::cout << "el " << el << " is not in the tree\n";
    else
      std::cout << "the tree is empty\n";
}

template<class T>
void BST<T>::deleteByMerging(BSTNode<T>*& node) {
  BSTNode<T> *tmp = node;
  if (node != 0) {
    if (node->right == 0){           // node has no right child: its left
      node = node->left;     // child (if any) is attached to its parent;
    } else
      if (node->left == 0)   // node has no left child: its right
        node = node->right;    // child is attached to its parent;
      else {                      // be ready for merging subtrees;
        tmp = node->left;      // 1. move left
        while (tmp->right != 0)// 2. and then right as far as possible;
          tmp = tmp->right;
        tmp->right = node->right;// 3. establish the link between the
                                //    the rightmost node of the left
                                //    subtree and the right subtree;
        tmp = node;             // 4.
        node = node->left;     // 5.
      }
    delete tmp;                 // 6.
   }
}

template<class T>
void BST<T>::findAndDeleteByMerging(const T& el) {
  BSTNode<T> *node = root, *prev = 0;
  while (node != 0 && node->el != el) {
    prev = node;
    if (el < node->el)
      node = node->left;
    else
      node = node->right;
  }
  if (node != 0 && node->el == el)
    if (node == root)
      deleteByMerging(root);
    else
      if (prev->left == node)
        deleteByMerging(prev->left);
      else
        deleteByMerging(prev->right);
  else
    if (root != 0)
      std::cout << "el " << el << " is not in the tree\n";
    else
      std::cout << "the tree is empty\n";
}

template<class T>
void BST<T>::breadthFirst() {
  std::queue<BSTNode<T>*> fila;
  BSTNode<T> *p = root;
  if (p != 0) {
      fila.push(p);
      while (!fila.empty()) {
          p = fila.front();
          fila.pop();
          visit(p);
          if (p->left != 0)
               fila.push(p->left);
          if (p->right != 0)
               fila.push(p->right);
      }
  }
}
