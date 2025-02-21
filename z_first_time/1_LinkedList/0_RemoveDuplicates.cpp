#include <iostream>
#include <cassert>
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList) {
  // Write your code here.
  LinkedList * iterator = linkedList;
  
  //Code below modify the linkedList
  while(iterator->next != nullptr) {

    int currentValue = iterator->value;
    int nextValue = iterator->next->value;
    
    while(nextValue == currentValue) {

      if (iterator->next->next == nullptr) {
        iterator->next = nullptr;
        return linkedList;

      } else {
        iterator->next = iterator->next->next;        
      }

      currentValue = iterator->value;
      nextValue = (iterator->next)->value;

    }
    iterator = iterator->next;
  }
  return linkedList; 
}

int main() {
  LinkedList * linkedList = new LinkedList(1);

  linkedList->next = new LinkedList(1);
  LinkedList * twoNode = linkedList->next;

  twoNode->next = new LinkedList(3);
  LinkedList * threeNode = twoNode->next;

  threeNode->next = new LinkedList(4);
  LinkedList * fourNode = threeNode->next;

  fourNode->next = new LinkedList(4);
  LinkedList * fifthNode = fourNode->next;

  fifthNode->next = new LinkedList(4);
  LinkedList * sixNode = fifthNode->next;

  sixNode->next = nullptr;

  LinkedList * result = removeDuplicatesFromLinkedList(linkedList);


  assert(result == linkedList);
  assert(result->next->value == 3);
  assert(result->next->next->next == nullptr);
  assert(result->next->next->value == 4);

  delete linkedList;
  delete twoNode;
  delete threeNode;
  delete fourNode;
  delete fifthNode;
  delete sixNode;

}