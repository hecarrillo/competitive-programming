#include <bits/stdc++.h>

using namespace std;

int main(){

}


void reverse(){
        SinglyLinkedListNode* currentNode = head;
        SinglyLinkedListNode* before = nullptr;
        SinglyLinkedListNode* after = nullptr;

        while(current -> next != nullptr){
            after = currentNode -> next;
            currrentNode -> next = before;
            before = currentNode;
            currentNode = after;
        }
    }
