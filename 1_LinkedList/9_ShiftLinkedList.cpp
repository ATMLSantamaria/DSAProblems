#include <iostream>
#include <cmath>
using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList* shiftLinkedList(LinkedList* head, int k) {
  LinkedList* fast_ptr = head;
  LinkedList* slow_ptr = head;
  int counter = 1;
  
  if (k > 0) {
    while(fast_ptr->next != nullptr) {
      fast_ptr = fast_ptr->next;
      slow_ptr = slow_ptr->next;
      if (counter <= k) {
        slow_ptr = head;
      }
      counter++;
    }

    if (k == counter) {
      return head;
    } else if (k > counter) {
      return shiftLinkedList(head, k - counter);
    }

    fast_ptr->next = head;
    head = slow_ptr->next;
    slow_ptr->next = nullptr;
    
  } else if (k < 0) {

    int inverse_k = 0;
    int total_size = 1;
    
    while(fast_ptr->next != nullptr) {
      total_size++;
      fast_ptr = fast_ptr->next;
      slow_ptr = slow_ptr->next;
      if (counter <= abs(k)) {
        slow_ptr = head;
      }
      counter++;
    }

    inverse_k = total_size - abs(k);
    return shiftLinkedList(head,inverse_k);

  } else {
    return head;
  }  
  return head;
}

void PrintLinkedList(LinkedList * head) ;
int main() {
        //Some nodes
  LinkedList * a = new LinkedList(0);
  LinkedList * b = new LinkedList(1);
  LinkedList * c = new LinkedList(2);
  LinkedList * d = new LinkedList(3);
  LinkedList * e = new LinkedList(4);
  LinkedList * f = new LinkedList(5);

  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = nullptr;

  PrintLinkedList(a);

  LinkedList * res = shiftLinkedList(a,1);

  PrintLinkedList(res);


}

void PrintLinkedList(LinkedList * head) {
  LinkedList * iterator = head;
  while (iterator != nullptr) {
    std::cout << iterator->value << " -> ";
    iterator = iterator->next;
  }

  std::cout << "\n";
}