#include <vector>
#include <cassert>
using namespace std;

//Complexity T O(N) S (N + N*8bytes) Vector of pointers

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

void TraverseAndStore(LinkedList * iterator, std::vector<LinkedList*> & storage);

LinkedList* MiddleNodeStorage(LinkedList* linkedList) {
  // Write your code here.
  std::vector<LinkedList*> storage_;
  int index = 0;
  LinkedList * iterator = linkedList;

  //Traverse List and storage
  TraverseAndStore(iterator,storage_);

  // Determine middle index
  // If even like 8, 8 / 2 = 4. That is exactly the 5 position, the one we want to return
  // If odd like 7, 7 /2 = 3 (since is an int). That is also the position we want to return, the 4th
  // right in the middle
  // Even if 1, index = 0
  
  index = storage_.size() / 2;
    
  return storage_[index];
}

void TraverseAndStore(LinkedList * iterator, std::vector<LinkedList*> & storage) {
  while (iterator != nullptr) {
    storage.push_back(iterator);
    iterator = iterator->next;
  }
}

int TraverseAndCount(LinkedList * iterator);
LinkedList* MiddleNodeTwoIterations(LinkedList* linkedList) {
  // Write your code here.

  //Create Iterator
  LinkedList* iterator = linkedList;
  //Count
  int size = TraverseAndCount(iterator);

  //reset iterator to the beginning
  //iterator = linkedList;

  if (size == 1) return linkedList;

  int index = size / 2;
  //If size 3 -> index = 1
  //If size 4 -> index = 2

  for (int i = 0;i < index;++i){
    iterator = iterator->next; 
  }
 
  return iterator;
}

int TraverseAndCount(LinkedList * iterator) {
  int counter = 1;
  while (iterator->next != nullptr) {
    iterator = iterator->next;
    ++counter;
  }
  return counter;
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

  LinkedList * result = MiddleNodeStorage(linkedList);
  //1 - 1 - 3 - 4 - 4 -4
   
  assert(fourNode == result);
  result = nullptr;

  result = MiddleNodeTwoIterations(linkedList);
  assert(result == fourNode);
  delete linkedList;
  delete twoNode;
  delete threeNode;
  delete fourNode;
  delete fifthNode;
  delete sixNode;

}
