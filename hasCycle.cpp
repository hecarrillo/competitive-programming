/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
  unordered_set<SinglyLinkedListNode> visited;
  SinglyLinkedListNode * current = head;
  while(current -> next != NULL){
    if (visited.find(*current) == visited.end()){
      visited.insert(*current);
      current = current -> next;
    } else return true;
  }
  return false;
}
