#include <iostream>
#include<cassert>

using namespace std;

class Node {
 public:
  int value;
  Node* prev;
  Node* next;

  Node(int value) :value(value) {
  };
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
 public:
  Node* head;
  Node* tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void setHead(Node* node) {
    // Protect in case node already in LL removing it from the LL
    remove(node);
    node->next = nullptr;
    node->prev = nullptr;

    //Protect Empty List
    if (head == nullptr && tail == nullptr) {
      head = node;
      tail = node;
      return;
  
    }

    //Insert the node before
    insertBefore(head,node);

  }

  void setTail(Node* node) {
    // Write your code here.
    remove(node);
    node->next = nullptr;
    node->prev = nullptr;

    //Protect Empty List
    if (head == nullptr && tail == nullptr) {
      head = node;
      tail = node;
      return;
    }

    insertAfter(tail,node);
  }

  void insertBefore(Node* node, Node* nodeToInsert) {
    // Protect in case node already in LL removing it from the LL
    remove(nodeToInsert);

    if (node != head) {
      nodeToInsert->prev = node->prev;
      nodeToInsert->next = node;

      node->prev->next = nodeToInsert;
      node->prev = nodeToInsert;

    } else {
      nodeToInsert->prev = nullptr;
      nodeToInsert->next = node;

      node->prev = nodeToInsert;

      head = nodeToInsert;
    }


  }

  void insertAfter(Node* node, Node* nodeToInsert) {
    // Protect in case node already in LL removing it from the LL
    remove(nodeToInsert);

    if (node != tail) {
      nodeToInsert->prev = node;
      nodeToInsert->next = node->next;

      node->next->prev = nodeToInsert;
      node->next = nodeToInsert;
    } else {
      nodeToInsert->next = nullptr;
      nodeToInsert->prev = node;

      node->next = nodeToInsert;

      tail = nodeToInsert;
    }
  }

  void insertAtPosition(int position, Node* nodeToInsert) {
    // Write your code here.
    Node * iterator = head;
    int p = 1;
    if (position == p) {
      setHead(nodeToInsert);
      return;
    }

    while (iterator != nullptr) {
      if (p == position) {
        insertBefore(iterator,nodeToInsert);
      }

      iterator = iterator->next;
      ++p;
    }

  }

  void removeNodesWithValue(int value) {
    Node * iterator = head;
    while(iterator != nullptr) {
      Node * toRemove = iterator;
      iterator = iterator->next;     
      if (toRemove->value == value) {
        remove(toRemove);
      }
    }
  }

  void remove(Node* node) {

    if (node == head) { //tail
      head = head->next;
    }
    if (node == tail) { //head
      tail = tail->prev;
    } 
    removeNodeBindings(node);
  }
  

  bool containsNodeWithValue(int value) {
    // Write your code here.
    Node * iterator = head;
    while(iterator != nullptr) {
      if (iterator->value == value){
        return true;
      }
      iterator = iterator->next;
    }
    return false;
  }

void removeNodeBindings(Node * node) {
  if (node->prev != nullptr) {
    node->prev->next = node->next;
  }
  if (node->next != nullptr) {
    node->next->prev = node->prev;
  }
  node->prev = nullptr;
  node->next = nullptr;
}

  void PrintLinkedList() {
    Node * iterator = head;
    std::cout << "nullptr -> ";
    while (iterator != nullptr) {
      std::cout << iterator->value << " -> ";
      iterator = iterator->next;
    }
    std::cout << "nullptr \n";
  }

  void PrintHead() {
    std::cout << "Current Head is " << head->value << std::endl;
  }

  void PrintTail() {
    std::cout << "Current Tail is " << tail->value << std::endl;
  }
};


DoublyLinkedList * CreateDLL(Node * a,Node * b,Node * c,Node * d,Node * e);

int main() {

  Node * a = new Node(3);
  Node * b = new Node(4);
  Node * c = new Node(5);
  Node * d = new Node(6);
  Node * e = new Node(7);
  Node * x = new Node(91);
  Node * z = new Node(6690);
  Node * h = new Node(100);

  DoublyLinkedList * myLL = CreateDLL(a,b,c,d,e);

  myLL->remove(c);
  myLL->remove(e);
  myLL->removeNodesWithValue(4);

  myLL->insertAtPosition(1,h);
  myLL->insertBefore(d,z);
  
  myLL->setHead(x);

  myLL->PrintLinkedList();

  myLL->insertAtPosition(1,myLL->tail);
  myLL->PrintLinkedList();
  myLL->setTail(myLL->head);
  myLL->PrintLinkedList();

  myLL->removeNodesWithValue(3);
  myLL->PrintLinkedList();

  assert(myLL->containsNodeWithValue(6690) == true);
  assert(myLL->containsNodeWithValue(3) == false);

  myLL->remove(z);
  myLL->PrintLinkedList();

  DoublyLinkedList * empty = new DoublyLinkedList();
  Node * no = new Node(10);
  empty->setHead(no);
  empty->remove(no);

  empty->PrintLinkedList();

  


  delete a;
  delete b;
  delete c;
  delete d;
  delete e;
}

DoublyLinkedList * CreateDLL(Node * a,Node * b,Node * c,Node * d,Node * e) {
   a->prev = nullptr;
   a->next = b;
   
   b->prev = a;
   b->next = c;
   
   c->prev = b;
   c->next = d;
   
   d->prev = c;
   d->next = e;
   
   e->prev = d;
   e->next = nullptr;

   DoublyLinkedList * my_linked_list = new DoublyLinkedList();
   my_linked_list->head = a;
   my_linked_list->tail = e;
   return my_linked_list;
}

