#include <vector>
#include <iostream>
using namespace std;

// This is an input class. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

//  T O(n+m)  S O(1)
LinkedList* MergeLinkedLists(LinkedList* headOne, LinkedList* headTwo) {
  // Write your code here.
  //Iterators for each list. Unnecesaries since I could use headOne headTwo
  LinkedList* it_one = headOne;
  LinkedList* it_two = headTwo;

  //Head new list
  LinkedList* new_head;
  LinkedList* it_new;

  //it_one/two moves forward when the vlaue they point is inserted in new list
  //it_new always point to the last element of the new_list;

  //Find new head. The problem say that always there is at least one node in each list
  //So we are safe here. If not we should protect against it_one/two pointing to null
  if (it_one->value > it_two->value) {
    new_head = it_two;
    it_new = new_head;
    it_two = it_two->next;
  } else {
    new_head = it_one;
    it_new = new_head;
    it_one = it_one->next;
  }
  
  //Iterate through the lists
  while (it_one != nullptr && it_two != nullptr) {
    if (it_one->value > it_two->value) {
      it_new->next = it_two;
      it_new = it_new->next;
      it_two = it_two->next;
    }
    else {
      it_new->next = it_one;
      it_new = it_new->next;
      it_one = it_one->next;
    } 
  }

  //One of the list reach the nullptr, so simply add the rest of the other list to the new list
  if (it_one != nullptr) {
    it_new->next = it_one;
  }
  if (it_two != nullptr) {
    it_new->next = it_two;
  }
  return new_head;
}

void PrintLinkedList(LinkedList * head) ;

int main() {
       //Some nodes
  LinkedList * a = new LinkedList(5);
  LinkedList * b = new LinkedList(15);
  LinkedList * c = new LinkedList(25);
  LinkedList * d = new LinkedList(35);
         //Some nodes
  LinkedList * aa= new LinkedList(1);
  LinkedList * bb = new LinkedList(2);
  LinkedList * cc = new LinkedList(26);
  LinkedList * dd = new LinkedList(27);


  a->next = b;
  b->next = c;
  c->next = d;
  d->next = nullptr;

  aa->next = bb;
  bb->next = cc;
  cc->next = dd;
  dd->next = nullptr;

  LinkedList * res = MergeLinkedLists(a,aa);

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