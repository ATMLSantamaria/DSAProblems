//You are given a LL list with a loop. Return the node where the loop is initiated

#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value):value(value){};
};


//Clever Solution. T: O(n) S: O(1)
LinkedList* FindLoopClever(LinkedList* head) {
  LinkedList* first = head; //normal velocity. Move one node per iteration
  LinkedList* second = head; //double velocity. Move two nodes per iteration

  //We need to iterate the first time or the condition will not enter
  first = first->next;
  second = second->next->next;
  while(first != second) {
    first = first->next;
    second = second->next->next;
  }
  //In this moment both first and second point to N
  //We know distance from head to the first node in the loop D is equal to
  //distance from N to first node in the loop.

  //We move S to head again, and iterate with both them at the same time
  second = head;
  while(first != second) {
    first = first->next;
    second = second->next;
  }
  return first;
}

//Brute force approach using a Hash Table. T: O(n) S: O(n)
LinkedList* FindLoopBruteForce(LinkedList* head) {
  // Write your code here.
  std::unordered_map<LinkedList*,LinkedList*> storage;
  LinkedList* iterator = head;
  LinkedList* check_repeat;
  while(iterator != nullptr) {
    if (storage.find(iterator) != storage.end()) {
      return iterator;
    }
    storage[iterator] = iterator;
    iterator = iterator->next;
    
  }
  return nullptr;
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
  d->next = b;

  assert(FindLoopBruteForce(a) == FindLoopClever(a));
  assert(b == FindLoopClever(a));



}