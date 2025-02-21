//Reverse in place a SinglyLinkedList
#include <cassert>
using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

// T O(n) S O(1)
LinkedList* ReverseLinkedList(LinkedList* head) {
  // Write your code here.
  LinkedList* swap_to_next = head;
  LinkedList* current_node = head;
  LinkedList* prev_node = nullptr;

  //First Iteration outside


  while(swap_to_next != nullptr) {
    //Keep track of next in original list
    swap_to_next = current_node->next;
    //Rever next in current node
    current_node->next = prev_node;
  
    //keep track of prev node for the next reversal
    prev_node = current_node;
    //Move to next node
    current_node = swap_to_next;
    
  }
  
  return prev_node;
}

int main() {
      //Some nodes
  LinkedList * a = new LinkedList(9);
  LinkedList * b = new LinkedList(8000);
  LinkedList * c = new LinkedList(6);
  LinkedList * d = new LinkedList(100);


  a->next = b;
  b->next = c;
  c->next = d;
  d->next = nullptr;

  LinkedList * reverted_linked_list = ReverseLinkedList(a);

  assert(reverted_linked_list == d);
  assert(a->next == nullptr);



}