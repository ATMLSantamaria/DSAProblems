#include <unordered_map>
#include <cassert>
#include <cmath>
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

// Time O(n+m) Space O(1)
LinkedList* mergingLinkedListsOptimized(LinkedList* linkedListOne, LinkedList* linkedListTwo) {
  LinkedList * iterator_one = linkedListOne;
  LinkedList * iterator_two = linkedListTwo;
  int length_one = 0;
  int length_two = 0;
  while (iterator_one != nullptr) {
    ++length_one;
    iterator_one = iterator_one->next;
  }
  while (iterator_two != nullptr) {
    ++length_two;
    iterator_two = iterator_two->next;
  }

  int diff = abs(length_one - length_two);
  
  if (length_two > length_one) {

    iterator_one = linkedListOne;
    iterator_two = linkedListTwo;
    for (int i = 0; i < diff;++i){
      iterator_two = iterator_two->next;
    }
    while (iterator_one != nullptr && iterator_two != nullptr) {
      if (iterator_one == iterator_two) {
        return iterator_two;
      }
      iterator_one = iterator_one->next;
      iterator_two = iterator_two->next;
    }

  } else if (length_one > length_two) {

    iterator_one = linkedListOne;
    iterator_two = linkedListTwo;
    for (int i = 0; i < diff;++i){
      iterator_one = iterator_one->next;
    }
    while (iterator_one != nullptr && iterator_two != nullptr) {
      if (iterator_one == iterator_two) {
        return iterator_two;
      }
    iterator_one = iterator_one->next;
    iterator_two = iterator_two->next;
    }

  } else {
    iterator_one = linkedListOne;
    iterator_two = linkedListTwo;
    while (iterator_one != nullptr && iterator_two != nullptr) {
      if (iterator_one == iterator_two) {
        return iterator_two;
      }
    iterator_one = iterator_one->next;
    iterator_two = iterator_two->next;
    }
  }

  return nullptr;
}

// Time O(n+m) Space O(n)
LinkedList* mergingLinkedLists(
  LinkedList* linkedListOne, LinkedList* linkedListTwo
) {
  // Write your code here.
  std::unordered_map<LinkedList*,LinkedList*> track_nodes;
  LinkedList * iterator_one = linkedListOne;
  LinkedList * iterator_two = linkedListTwo;

  while(iterator_one != nullptr ) {
    track_nodes[iterator_one] = iterator_one;
    iterator_one = iterator_one->next;
  }
  while(iterator_two != nullptr) {
    if (track_nodes.find(iterator_two) != track_nodes.end()) {
      return track_nodes[iterator_two];
      
    }
    iterator_two = iterator_two->next; 
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
  d->next = nullptr;


  LinkedList * bb = new LinkedList(1);
  LinkedList * cc = new LinkedList(1);
  bb->next = cc;
  cc->next = b;

  //Both list converge in b
  assert(mergingLinkedListsOptimized(a,bb)->value == 8000);

}