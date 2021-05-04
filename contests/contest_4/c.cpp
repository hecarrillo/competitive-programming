#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;

    Node (int x) : data(x), left(nullptr), right(nullptr) {}
};


    /*The tree node has data, left child and right child
    class Node {
        int data;
        Node* left;
        Node* right;
    };
    */

    // ESCRIBE EN ESTA SECCIÓN TU SOLUCIÓN
    // DEBES ENVIAR SOLO ESTA SECCIÓN AL JUEZ
    // PUEDES USAR FUNCIONES AUXILIARES
    bool check (Node * root, int min, int max) {
      if(root -> left == nullptr && root -> right == nullptr) return true;
      int data = root -> data;
      if (root -> left != nullptr && root -> right != nullptr) {
        if (root -> left -> data < data && root -> left -> data > min && root -> right -> data > data && root -> right -> data < max) {
         return check(root -> right, data, max) && check(root -> left, min, data);
        } else return false;
      } else if (root -> left == nullptr && root -> right != nullptr) {
        if (root -> right -> data > data && root -> right -> data < max) return check(root -> right, data, max);
        else return false;
      } else if (root -> right == nullptr && root -> left != nullptr) {
        if (root -> left -> data < data && root -> left -> data > min) return check(root -> left, min, data);
        else return false;
      }
      return true;
    }

    bool checkBST(Node* root) {
     if(root == nullptr) return true;
     if(root -> left == nullptr && root -> right == nullptr) return true;
     int data = root -> data;
     if (root -> left != nullptr && root -> right != nullptr) {
       if (root -> left -> data < data && root -> right -> data > data) {
        return check(root -> right, data, 2147483647) && check(root -> left, -2147483648, data);
       } else return false;
     } else if (root -> left == nullptr && root -> right != nullptr) {
       if (root -> right -> data > data) return check(root -> right, data, 2147483647);
       else return false;
     } else if (root -> right == nullptr && root -> left != nullptr) {
       if (root -> left -> data < data) return check(root -> left, -2147483648, data);
       else return false;
     }
     return true;
    }



    // TERMINA LA SECCIÓN DE CÓDIGO SOLUCIÓN

int main()
{
    // Caso de prueba 1

     // Node *root        = new Node(3);
     // root->left        = new Node(5);
     // root->right       = new Node(2);
     // root->left->left  = new Node(1);
     // root->left->right = new Node(4);
     // root->right->left = new Node(6);

    //Resultado esperado: NO


    // Caso de prueba 2

    Node *root        = new Node(10);
    root->left        = new Node(5);
    root->right       = new Node(15);
    root->left->left  = new Node(-2);
    root->left->right = new Node(7);
    root->right->left = new Node(11);
    root->right->right = new Node(17);

    //Resultado esperado: YES


    if (checkBST(root))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
