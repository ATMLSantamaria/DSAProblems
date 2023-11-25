using namespace std;
#include <iostream>
#include <stack>

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

// This is the classical algorithm  of sum that we stuty in school
int ForNext(int sum) {
  return sum >= 10 ? 1 : 0;
}
int Sum(int sum) {
  return sum >=10 ? sum - 10 : sum;
  
}

//Time O(n) Space O(n)
LinkedList* sumOfLinkedLists(
  LinkedList* linkedListOne, LinkedList* linkedListTwo) {
  //We assume they dont pass us a nullptr list for any of them.
  //If that would be the case the solution is trivial.
  int a = linkedListOne->value;
  int b = linkedListTwo->value;
 
//  int for_next = ((a + b) >= 10) ? 1 : 0; // me llevo una o no 
  int for_next = ForNext(a + b);
//  int sum = ((a + b) >=10 ) ? a + b - 10 : a + b; 
  int sum = Sum(a + b);
  //Create the new linked List
  LinkedList* res = new LinkedList(sum);
  LinkedList * itNewList = res;

  LinkedList* iteratorOne = linkedListOne->next;
  LinkedList* iteratorTwo = linkedListTwo->next;



  while (iteratorOne != nullptr && iteratorTwo != nullptr) {
    //First required computation
    a = iteratorOne->value;
    b = iteratorTwo->value;
    
    sum = a + b + for_next; 
    for_next = ForNext(sum);
    sum = Sum(sum);

    //Second create the new node
    LinkedList * node = new LinkedList(sum);
    node->next = nullptr;

    //Third append new node to the new Linked List
    itNewList->next = node;

    //Fourth update all iterators
    itNewList = node;
    iteratorOne = iteratorOne->next;
    iteratorTwo = iteratorTwo->next;
  }
  //Check how to continue until the end
  LinkedList* iterator_one_or_two = nullptr;
  //If iteratorOne was equal to nullptr, we get the desired result in next line.
  //Since if iteratorTwo is equal to nullptr, then iterator_one_or_two is equal iteratorOne
  //Therefore if iteratorOne has a value, such value is preserved, and if is equal to nullptr
  //We know both were equal to nullptr
  iterator_one_or_two = (iteratorOne != nullptr) ? iteratorOne : nullptr;
  iterator_one_or_two = (iteratorTwo != nullptr) ? iteratorTwo : iteratorOne;
  //If iterator one_or_two equal nullptr means both list were of equal size.
  //If for_next = 1 we append one last node, and if not we return
  if (iterator_one_or_two == nullptr && for_next == 0) {
    return res;
  } else if (iterator_one_or_two == nullptr && for_next == 1) {
    //WE need one last node
    LinkedList * node = new LinkedList(1);
    node->next = nullptr;
    itNewList->next = node;
    return res;
  }
  //If iterator_one_or_two != nullptr we have to continue
  while (iterator_one_or_two != nullptr) {
    //First required computation
    a = iterator_one_or_two->value;
    sum = a + for_next; 
    for_next = ForNext(sum);
    sum = Sum(sum);

    //Second create the new node
    LinkedList * node = new LinkedList(sum);
    node->next = nullptr;

    //Third append new node to the new Linked List
    itNewList->next = node;

    //Fourth update all iterators
    itNewList = node;
    iterator_one_or_two = iterator_one_or_two->next;    
  }

  //Finally check if for_next is equal to 1 or 0
  if (for_next == 0) {
    return res;
  } else  {
    //We need one last node
    LinkedList * node = new LinkedList(1);
    node->next = nullptr;
    itNewList->next = node;
    return res;
  }
  return nullptr;
}












void PrintLinkedList(LinkedList * head);
int main() {
    //Some nodes
  LinkedList * a = new LinkedList(9);
  LinkedList * b = new LinkedList(9);
  LinkedList * c = new LinkedList(9);


  a->next = b;
  b->next = c;
  c->next = nullptr;


  LinkedList * aa = new LinkedList(1);
  LinkedList * bb = new LinkedList(1);
  LinkedList * cc = new LinkedList(1);


  aa->next = bb;
  bb->next = cc;
  cc->next = nullptr;

  LinkedList * sum = sumOfLinkedLists(a,aa);

  PrintLinkedList(sum);

  
}



void PrintLinkedList(LinkedList * head) {
  LinkedList * iterator = head;
  std::stack<int> res;
  while (iterator != nullptr) {
    //std::cout << iterator->value << " -> ";
    res.push(iterator->value);
    iterator = iterator->next;
  }
  while(!res.empty()) {
    std::cout << res.top();
    res.pop();
  }

  std::cout << "\n";
}