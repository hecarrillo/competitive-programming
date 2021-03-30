#include <bits/stdc++.h>
#include <cstddef>


using namespace std;

struct Node{
  Node * next;
  int value;
  string name;
  Node (int x, string nm){
    value = x;
    name = nm;
    next = NULL;
  }
};

struct linkedList {
  Node * head;
  linkedList(){
    head = NULL;
  }
};

void push(linkedList * list, Node * newNode){
  if (list -> head == NULL){
    list -> head = newNode;
  } else{
    Node * current = & (*(*list).head);
    while(current -> next != NULL){
      current = & (*(*current).next);
    }
    (*current).next = newNode;
  }
}

void printLLvalues(linkedList * list){
  Node * current = list -> head;
  while(current -> next != NULL){
    cout << current -> value << ", ";
    current = current -> next;
  }
  cout << current -> value << "\n";
}

/**
Suponiendo que si existe el valor que se intenta borrar
**/
void deleteNode(linkedList * list, string name){
  Node * last = list -> head;
  if(last -> name == name){
    list -> head = last -> next;
    return;
  }
  Node * current = last -> next;
  while(current -> name != name){
    last = current;
    current = current -> next;
  }
  last -> next = current -> next;
  delete current;
}

int main() {
  int n;
  linkedList * myLinkedList = new linkedList();
  cout << "Insert number of items in linkedList" << "\n";
  cin >> n;
  for (int i = 0; i < n; i++){
    int val;
    string nm;
    cin >> val >> nm;
    Node * temp = new Node(val, nm);
    push(myLinkedList, temp);
  }
  cout << "Enter the name of the Node to delete" << "\n";
  string nameToDelete;
  cin >> nameToDelete;
  deleteNode(myLinkedList, nameToDelete);

  printLLvalues(myLinkedList);
}
