#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
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

    int dfs(Node * root, int count) {
        if (root == nullptr) return count;
        else return max({dfs(root -> left, count + 1), dfs(root -> right, count + 1)});
    }

    int height ( Node* root, int level = 0 ) {
      if (root == nullptr) return level;
      return max({dfs(root -> left, 0), dfs(root -> right, 0)});
    }

    // TERMINA LA SECCIÓN DE CÓDIGO SOLUCIÓN

}; //End of Solution


int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    int height = myTree.height(root);

  	std::cout << height;

    return 0;
}
