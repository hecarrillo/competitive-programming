#include <bits/stdc++.h>

using namespace std;


template<typename T>
struct Node {
  Node<T> * left;
  Node<T> * right;
  T value;

  Node(T data): left(nullptr), right(nullptr), value(data) {}
};

template<typename T>
struct BinarySearchTree {
  Node<T> * _root;
  size_t _size;

  BinarySearchTree(): _root(nullptr), _size(0) {}

  private:
    bool search(Node<T>* root, T value) {
      if (root == nullptr) return false;
      if (value == root -> value) return true;
      if (value > root -> value) {
        return search(root -> right, value);
      } else {
        return search(root -> left, value);
      }
    }
    Node<T> * insert(Node<T>* root, T value) {
      if (root == nullptr) {
        return new Node<T>(value);
      }
      if (value < root -> value) {
        root -> left = insert(root -> left, value);
      }
      if(value > root -> value) {
        root -> right = insert(root -> right, value);
      }
      return root;
    }

    Node<T> * findMin(Node<T> * root) {
      if (root == nullptr) return root;
      if (root -> left == nullptr) return root;
      else return findMin(root -> left);
    }

    Node<T> * findMax(Node<T> * root) {
      if (root == nullptr) return root;
      if (root -> right == nullptr) return root;
      else return findMax(root -> right);
    }

    Node<T> * remove(Node<T> * root, T value) {
      if (root == nullptr) return root;
      if (root -> value == value) {
        if (root -> left == nullptr && root -> right == nullptr) {
          delete root;
          return nullptr;
        } else if (root -> left == nullptr) {
          Node<T> * temp = root -> right;
          delete root;
          return temp;
        } else if (root -> right == nullptr) {
          Node<T> * temp = root -> left;
          delete root;
          return temp;
        } else {
          Node<T> * minRightBranch = findMin(root);
          root -> value = minRightBranch -> value;
          root -> right = remove(root -> left, root -> value);
        }
      } else if (value < root -> value) {
        root -> left = remove(root -> left, value);
      } else if (value > root -> value) {
        root -> right = remove(root -> right, value);
      }
      return root;
    }

    // TODO: iterative pre order.
    void printPreorder(Node<T> * root) {
      if(root == nullptr) return;

      cout << root -> value << " ";

      printPreorder(root -> left);
      printPreorder(root -> right);
    }

    void printPreorderIter(Node<T> * root) {
      Node<T> * aux = root;
      stack<Node<T> *> stack;
      while (aux != nullptr) {
        cout << aux -> value << " ";

        Node<T> * left = aux -> left;
        Node<T> * right = aux -> right;

        if (left != nullptr and right != nullptr) {
          stack.push(right);
          aux = left;
        } else if (left == nullptr and right == nullptr) {
          if(stack.empty()) break;
          aux = stack.top();
          stack.pop();
        } else if (left == nullptr and right != nullptr) {
          aux = right;
        } else if (left != nullptr and right == nullptr) {
          aux = left;
        }
      }
      return;
    }

  public:
    bool search( T value ) {
        return search( _root, value );
    }
    bool insert( T value ) {
        int currentSize = _size;
        _root = insert( _root, value );
        if ( currentSize < _size ) {
            return true;
        }
        return false;
    }
    bool remove( T value ) {
        int currentSize = _size;
        _root = remove( _root, value );
        if ( currentSize > _size ) {
            return true;
        }
        return false;
    }
    void printPreorder() {
        printPreorder(_root);
        cout << "\n";
    }
    void printPreorderIter() {
        printPreorderIter(_root);
        cout << "\n";
    }
    // void printInorder() {
    //     printInorder(_root);
    //     cout << "\n";
    // }
    // void printPostorder() {
    //     printPostorder(_root);
    //     cout << "\n";
    // }
    // void printLevelOrder() {
    //     printLevelOrder(_root);
    //     cout << "\n";
    // }
};

int main () {
  BinarySearchTree<int> bst;
  //value insertion
  vector<int> v = {37, 18, 60, 9, 24, 42, 77, 5, 12, 39, 97, 2, 7, 38, 41, 86, 101};
  for (auto x : v) bst.insert(x);
  cout << "Iterative preorder: " << "\n";
  bst.printPreorderIter();
  cout << "Recursive Preorder: " << "\n";
  bst.printPreorder();
  return 0;
}
