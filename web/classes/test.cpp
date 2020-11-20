/**
 * @author      : Guilherme Wachs Lopes (gwachs@fei.edu.br)
 * @file        : main
 * @created     : quinta out 22, 2020 21:11:06 -03
 */

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node {
private:
  Node<T>* father;
  Node<T>* left;
  Node<T>* right;
  T value;


public:
  T getValue () {
    return value;
  }
  Node () : father (nullptr), left (nullptr), right (nullptr) {
    value = T{};
  }
  Node (T value) : father (nullptr), left (nullptr), right (nullptr), value (value) {
  }

  friend class Tree<T>;
};

template <typename T>
class Tree {
private:
  Node<T>* root;
  int n;

  void print (Node<T>* x) {
    if (!x)
      return;

    print (x->left);
    cout << x->value << "\n";
    print (x->right);
  }

  void deleteSubTree (Node<T>* r) {
    if (!r)
      return;

    deleteSubTree (r->left);
    deleteSubTree (r->right);
    delete r;
  }

  int child (Node<T>* n) {
    return (n->left != nullptr) + (n->right != nullptr);
  }



  bool remove (Node<T>* node) {
    
    Node<T>* currentNode = root; 
    Node<T>* previousNode = nullptr;


    while (currentNode && currentNode->value != node->value) { 

        previousNode = currentNode; 

        if (node->value < currentNode->value) 
            currentNode = currentNode->left; 

        else
            currentNode = currentNode->right; 

    }   

    if (!currentNode) {
    	return false;
    } 


    if (!currentNode->left || !currentNode->right) { 

        Node<T>* newCurr; 

        if (!currentNode->left) 
            newCurr = currentNode->right; 
        else
            newCurr = currentNode->left; 

        if (!previousNode) 
            return true;  

        if (currentNode == previousNode->left) 
            previousNode->left = newCurr; 
        else
            previousNode->right = newCurr; 

      
        delete currentNode; 
        
     } else { 

        Node<T>* prv = nullptr; 
        Node<T>* temp; 

        temp = currentNode->right; 

        while (temp->left) { 
            prv = temp; 
            temp = temp->left; 

        } 

        if (prv) 
            prv->left = temp->right; 

        else
            currentNode->right = temp->right; 
        
        currentNode->value = temp->value; 
        delete temp;

    } 

    return true;
  }

public:
  Tree () : root (nullptr), n (0) {
  }

  bool insert (T value) {
    Node<T>* novo = new Node<T> (value);
    if (!novo)
      return false;

    if (!root) {
      root = novo;
      n++;
      return true;
    }

    Node<T>* atual = root;
    Node<T>* anterior = nullptr;

    while (atual) {
      anterior = atual;

      if (value <= atual->value)
        atual = atual->left;
      else
        atual = atual->right;
    }

    novo->father = anterior;
    if (value <= anterior->value)
      anterior->left = novo;
    else
      anterior->right = novo;

    n++;
    return true;
  }

  Node<T>* search (T value) {
    Node<T>* atual = root;
    while (atual) {
      if (value < atual->value)
        atual = atual->left;
      else if (value > atual->value)
        atual = atual->right;
      else
        return atual;
    }
    return nullptr;
  }

  void print () {
    print (root);
  }

  bool remove (T value) {
    //NÃO ALTERAR
    return remove (search (value));
  }

  ~Tree () {
    deleteSubTree (root);
  }
};

int main () {
  Tree<int> v;
  v.insert (315);
  v.insert (25);
  v.insert (325);
  v.insert (962);
  v.insert (687);
  v.insert (778);
  v.insert (695);
  v.insert (245);
  v.insert (299);
  v.insert (135);
  v.insert (50);
  v.insert (307);
  v.insert (640);
  cout << "=====================================" << endl;
  v.print ();
  v.insert (564);
  v.insert (222);
  v.insert (913);
  v.insert (105);
  v.insert (279);
  v.insert (45);
  v.insert (826);
  v.insert (75);
  v.insert (495);
  v.insert (962);
  v.insert (913);
  v.remove (315);
  cout << "=====================================" << endl;
  v.print ();
  v.remove (25);
  v.remove (325);
  v.remove (962);
  v.remove (687);
  v.remove (778);
  v.remove (695);
  v.remove (245);
  v.remove (299);
  v.remove (135);
  v.remove (50);
  v.remove (307);
  cout << "=====================================" << endl;
  v.print ();
  v.remove (640);
  v.remove (564);
  v.remove (222);
  v.remove (913);
  v.remove (105);
  v.remove (279);
  v.remove (45);
  v.remove (826);
  v.remove (75);
  v.remove (495);
  v.remove (962);
  v.remove (913);
  cout << "=====================================" << endl;
  v.print ();

  return 0;
}