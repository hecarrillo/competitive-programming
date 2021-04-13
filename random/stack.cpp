#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

struct Node {
  int data;
  Node * previous;
  Node (int a){
    data = a;
    previous = nullptr;
  }
};

struct Stack{
  Node * head;
  int size;
  Stack (){
    head = nullptr;
    size = 0;
  }
  void push (Node * newNode){
    newNode -> previous = head;
    head = newNode;
    size ++;
  }
  Node * pop () {
    if (!head) return nullptr;
    Node * temp = head;
    head = head -> previous;
    size--;
    return temp;
  }
  void print () {
    Node * curr = head;
    while(curr) {
      cout << curr -> data << " -> ";
      curr = curr -> previous;
    }
    cout << "bottom\n";
  }
  Node * peek () {
    return head;
  }
  int find (int find){
    Node * curr = head;
    int index = 0;
    while(curr) {
      if (curr -> data == find) return index + 1;
      curr = curr -> previous;
      index ++;
    }
    return -1;
  }
};

int main() {
  int n; cin >> n;
  Stack * myStack = new Stack();
  while (n--){
    int data; cin >> data;
    Node * newNode = new Node(data);
    myStack -> push(newNode);
  }
  myStack -> print();
  int size = myStack -> size;
  cout << "Size: " << size << "\n";
  cout << "Insert Node data to find: ";
  int data; cin >> data;
  cout << "Node in position (1 indexed): " << myStack -> find(data) << "\n";
  cout << "Popping..." << "\n";
  myStack -> pop();
  myStack -> print();

}
