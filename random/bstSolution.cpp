#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

template<typename T>
struct TreeNode {
    T value;

    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode( T data ) : value(data),
                         left(nullptr),
                         right(nullptr) {}
};


template<class T>
struct BinarySearchTree {
    TreeNode<T>*    _root;
    size_t          _size;

    BinarySearchTree() : _root(nullptr), _size(0) {}

private:
    /**
     * search : recibe la raíz de un árbol y un valor
     * a buscar en el árbol. Si el valor se encuentra
     * en el árbol, regresa true, de lo contrario
     * regresa false.
     */
    bool search ( TreeNode<T>* root, T value ) {
        /**
         * Caso base: El valor no se encuentra en el
         * árbol, por lo tanto regresamos false.
         */
        if ( root == nullptr ) return false;
        /**
         * Encontramos el valor que buscamos, por lo
         * tanto regresamos true.
         */
        if ( value == root -> value ) return true;
        /**
         * Si no caemos en los casos base, seguimos
         * buscando en nuestros hijos.
         * Si el valor que buscamos es menor al de la
         * raíz, buscamos en el subárbol izquierdo,
         * si es menor, buscamos en el subárbol derecho
         */
        if ( value < root -> value ) {
            return search ( root -> left, value );
        } else {
            return search( root -> right, value );
        }
    }

    /**
     * insert : Recibe la raíz de un árbol, y un valor
     * a insertar en el árbol. Regresa la raíz del
     * árbol después de realizar la inserción.
     */
    TreeNode<T>* insert ( TreeNode<T>* root, T value ) {
        /**
         * Llegamos al lugar donde debería estar el valor
         * a insertar, por lo tanto, regresamos un nuevo
         * nodo para que sea asignado cuando regresemos
         * de la recursividad.
         */
        if ( root == nullptr )
            return new TreeNode<T>(value);
        /**
         * Seguimos buscando el lugar donde debería de
         * estar el valor que se va a insertar
         */
        if ( value < root -> value ) {
            root -> left = insert( root -> left, value );
        } else if ( value > root -> value ) {
            root -> right = insert( root -> right, value );
        }
        /**
         * Regresamos la raíz con los hijos actualizados
         */
        return root;
    }

    /**
     * remove : recibe el nodo de un árbol y el valor a
     * eliminar. Regresa la nueva raíz del árbol o
     * subárbol después de realizar la aliminación del
     * nodo correspondiente
     */
    TreeNode<T>* remove( TreeNode<T>* root, T value ) {
        // El nodo que buscamos no está en el árbol
        // por lo que llegamos a un nodo nulo
        if ( root == nullptr ) return root;
        // Encontramos el nodo a eliminar
        if ( value == root -> value ) {
            // Caso 1: eliminamos un nodo hoja
            if ( root -> left == nullptr && root -> right == nullptr ) {
                delete root;
                return nullptr;
            // Caso 2: solo tenemos el hijo izquierdo
            } else if ( root -> right == nullptr ) {
                // asignamos a nuestro padre, nuestro hijo
                // izquierdo
                TreeNode<T>* leftChild = root -> left;
                delete root;
                return leftChild;
            // Caso 2: solo tenemos el hijo derecho
            } else if ( root -> left == nullptr ) {
                // asignamos a nuestro padre, nuestro hijo
                // derecho
                TreeNode<T>* rightChild = root -> right;
                delete root;
                return rightChild;
            // Caso 3: el nodo tiene ambos hijos
            } else {
                // obtenemos el nodo sucesor, intercambiamos
                // valores y eliminamos el sucesor
                TreeNode<T>* successor = getMinNode(root -> right);
                root -> value = successor -> value;
                root -> right = remove( root -> right, successor -> value );
            }
        /**
         * Seguimos buscando en nuestros hijos el nodo
         * a eliminar
         */
        } else if ( value < root -> value ) {
            root -> left = remove( root -> left, value );
        } else {
            root -> right = remove( root -> right, value );
        }
        // Regresamos la raíz actualizada
        return root;
    }

    /**
     * getMinNode : recibe el nodo de un árbol, y obtiene
     * el nodo con el valor MINIMO del árbol
     */
    TreeNode<T>* getMinNode ( TreeNode<T>* root ) {
        // Viajamos hasta el hijo que esté más a
        // la izquierda
        TreeNode<T>* minNode = root;
        while ( minNode -> left != nullptr )
            minNode = minNode -> left;
        return minNode;
    }

    /**
     * getMaxNode : recibe el nodo de un árbol, y obtiene
     * el nodo con el valor MAXIMO del árbol
     */
    TreeNode<T>* getMaxNode ( TreeNode<T>* root ) {
        TreeNode<T>* maxNode = root;
        while ( maxNode -> right != nullptr )
            maxNode = maxNode -> right;
        return maxNode;
    }

    /**
     * printPreorder : imprime los valores visitados
     * con el recorrido preorder.
     * (En cuanto visitemos un nodo, imprimimos su valor).
     */
    void printPreorder ( TreeNode<T>* root ) {
        if ( root == nullptr ) return;
        cout << root -> value << " ";
        printPreorder( root -> left );
        printPreorder( root -> right );
    }

    /**
     * printInorder : imprime los valores visitados
     * con el recorrido inorder.
     * (Imprimimos el valor de los nodos, después de
     * visitar su hijo izquierdo).
     */
    void printInorder ( TreeNode<T>* root ) {
        if ( root == nullptr ) return;
        printInorder( root -> left );
        cout << root -> value << " ";
        printInorder( root -> right );
    }

    /**
     * printPostorder : imprime los valores visitados
     * con el recorrido postorder.
     * (Imprimimos el valor de los nodos, después de
     * visitar sus dos hijos).
     */
    void printPostorder ( TreeNode<T>* root ) {
        if ( root == nullptr ) return;
        printPostorder( root -> left );
        printPostorder( root -> right );
        cout << root -> value << " ";
    }

    /**
     * printLevelOrder : imprime los valores visitados
     * con el recorrido por niveles.
     * (Imprimimos el valor de los nodos por niveles,
     * primero el primer nivel, después los del segundo
     * y así sucesivamente).
     */
    void printLevelOrder ( TreeNode<T>* root ) {
        queue<TreeNode<T>*> toCheck;
        queue<TreeNode<T>*> level;
        toCheck.push( root );
        TreeNode<T>* current;

        while ( !toCheck.empty() ) {
            current = toCheck.front();
            toCheck.pop();
            if ( current != nullptr )
                cout << current -> value << "\n";
            if ( current -> left != nullptr )
                toCheck.push( current -> left );
            if ( current -> right != nullptr )
                toCheck.push( current -> right );
        }
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
    void printInorder() {
        printInorder(_root);
        cout << "\n";
    }
    void printPostorder() {
        printPostorder(_root);
        cout << "\n";
    }
    void printLevelOrder() {
        printLevelOrder(_root);
        cout << "\n";
    }
};

int main () {
    BinarySearchTree<int> bst;
    // Insertamos valores al árbol
    vector<int> v = {37, 18, 60, 9, 24, 42, 77, 5, 12, 39, 97, 2, 7, 38, 41, 86, 101};
    for ( auto x : v ) bst.insert( x );


    return 0;
}
