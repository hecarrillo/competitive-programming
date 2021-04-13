/*
Name: Delete duplicate value Nodes
Status: AC
*/

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the removeDuplicates function below.

/*
*     int data;
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     SinglyLinkedListNode* next;
 * };
 *
 */

bool hasVisited (vector<int> & visited, int data){
  for (int & number : visited){
    if(number == data) return true;
  }
  return false;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode * current, SinglyLinkedListNode * previous){
  previous -> next = current -> next;
  return previous -> next;
}

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
  if(!head || !(head -> next)) return head;

  vector<int> visited;

  SinglyLinkedListNode * current = head -> next;
  SinglyLinkedListNode * previous = head;

  visited.push_back(head -> data);

  while(current) {
    if(hasVisited(visited, current -> data)){
      current = deleteNode(current, previous);
    } else {
      visited.push_back(current -> data);
      previous = current;
      current = current -> next;
    }
  }
  return head;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        SinglyLinkedListNode* llist1 = removeDuplicates(llist->head);

        print_singly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
