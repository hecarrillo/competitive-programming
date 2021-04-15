#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

struct Node {
  int data;
  Node * previous;
};

struct Stack{
  Node * head = nullptr;
  int size = 0;
  void print () {
    Node * curr = head;
    while(curr) {
      cout << curr -> data << " -> ";
      curr = curr -> previous;
    }
    cout << "bottom\n";
  }
  void push (int nodeData){
    head = new Node {nodeData, head};
    size ++;
  }
  Node * pop () {
    if (!head) return nullptr;
    Node * temp = head;
    head = head -> previous;
    size--;
    return temp;
  }
  Node * peek () {
    return head;
  }
  int findIndex (int find){
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
  cout << "Insert number of elements in the Stack: ";
  int n; cin >> n;
  cout << "Insert the node values: \n";
  Stack myStack;
  while (n--){
    int data; cin >> data;
    myStack.push(data);
  }
  myStack.print();
  cout << "Size: " << myStack.size << "\n";
  cout << "Insert Node data to find: ";
  int data; cin >> data;
  cout << "Node in position (1 indexed): " << myStack.findIndex(data) << "\n";
  cout << "Popping..." << "\n";
  myStack.pop();
  myStack.print();

}
