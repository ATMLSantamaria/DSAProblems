#include <vector>
#include <iostream>
using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value):value(value),next(nullptr){}
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};


//Complexity Time O(n) Space O(1)
void removeKthNodeFromEnd(LinkedList* head, int k) {
  // Write your code here.
  // Iterate with 2 pointers at head
  // First, move the first pointer k positions to the front so that is ahead of second k nodes
  // Now move both pointers together until first pointer reach the null at the end of the list
  // Because second pointer is k node behind first, now second pointer points to the node to be removed
 
  // AS OFTEN HAPPEN WITH LINKED LIST, to iterate with SEVERAL POINTERS is the WAY TO GO to solve Problems in the Optimum time.
 
  LinkedList *first, *second, *node_behind_second;
  first = head;
  second = head;

  // First move first k node to the front
  for (int i = 0; i < k;++i) {
    first = first->next;
  }

// If First in this moment is equal nullptr, imply that the element we need to remove is head.
// So we can directly take care of the Edge case
  if (first == nullptr) {
    head->value = head->next->value;
    head->next = head->next->next;
    return; //This return is of utmost importance to avoid segmentation fault
  }

  //Now move both pointers together until first reach nullptr
  while (first != nullptr) {
    node_behind_second = second;
    second = second->next;
    first = first->next;
  }

  // General case. Remove second
  node_behind_second->next = second->next;
}

void PrintLinkedList(LinkedList * head) {
  LinkedList * iterator = head;
  std::cout << "nullptr -> ";
  while (iterator != nullptr) {
    std::cout << iterator->value << " -> ";
    iterator = iterator->next;
  }
  std::cout << "nullptr\n";
}

int main() {
  //Some nodes
  LinkedList * head = new LinkedList(0);
  LinkedList * b = new LinkedList(1);
  LinkedList * c = new LinkedList(2);
  LinkedList * d = new LinkedList(3);

  head->next = b;
  b->next = c;
  c->next = d;
  d->next = nullptr;
  
  PrintLinkedList(head);

  removeKthNodeFromEnd(head,4);

  PrintLinkedList(head);
  
}
