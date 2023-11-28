#include <vector>
#include <cassert>
using namespace std;

//Each element is stricly bigger than all elements to its left, and smaller than elements to its right

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST& insert(int val) {
    // Write your code here.
    BST * iterator = this;
    BST * iterator_prev = this;
    while (iterator != nullptr) {
      if (val < iterator->value) {
        iterator_prev = iterator;
        iterator = iterator->left;
      } else {
        iterator_prev = iterator;
        iterator = iterator->right;
      }
    }
    if (val < iterator_prev->value) {
      iterator_prev->left = new BST(val);
    } else {
      iterator_prev->right = new BST(val);
    }
    return *this;
  }

  bool contains(int val) {
    BST * iterator = this;
    while (iterator != nullptr) {
      if (val == iterator->value) {
        return true;
      }
      if (val < iterator->value) {
        iterator = iterator->left;
      } else {
        iterator = iterator->right;
      }
    }
    return false;
  }

  BST& remove(int val) {
    if (this->left == nullptr && this->right == nullptr) {
      return *this;
    }
    
    BST * iterator = this;
    BST * parent = this;
    bool iterator_left_of_parent = false;
    //Search for Node tp be removed
    //Keep a pointer to the parent of that Node
    while (val != iterator->value) {
      parent = iterator;
      if (val < iterator->value) {
        iterator_left_of_parent = true;
        iterator = iterator->left;
      } else {
        iterator_left_of_parent = false;
        iterator = iterator->right;
      }
    }

    // Iterator now point to node to remove
    // Parent to its father

    //First easy cases
  
    //Iterator does not have subtrees
    if (iterator->right == nullptr && iterator->left == nullptr) {
      if (iterator_left_of_parent == true) {
        parent->left = nullptr;
      } else {
        parent->right = nullptr; 
      }
      return *this;
    }


    //iterator has only one subtree
    if (iterator->right == nullptr) {
      if (iterator_left_of_parent == true) {
        parent->left = iterator->left;
      } else {
        parent->right = iterator->left;
      }
      return *this;
    }

    if (iterator->left == nullptr) {
      if (iterator_left_of_parent == true) {
        parent->left = iterator->right;
      } else {
        parent->right = iterator->right;
      }
      return *this;
    }

    //Below most complex case

    //We need to find a node to replace the deleted one
    //We need to replace this node for the smalles element of hte right tree to keep this as a BST
    
    BST * second_it = iterator->right;
    BST * second_it_prev = iterator;
    BST * third_it_prev = nullptr;
    
    while(second_it != nullptr) { 
      third_it_prev = second_it_prev;
      //when finish we need the prev
      second_it_prev = second_it;
      //Always to the left to find the smallest element of the right tree
      second_it = second_it->left; 
    }

    //Note:
    // - iterator point to node to remove
    // - secondary iterator point to null
    // - secondary iterator prev point to the node to put in the place of iterator

    iterator->value = second_it_prev->value;
    
    //Delete the old appearence of the value that is not on place of the deleted one
    delete (second_it_prev);
    second_it_prev = nullptr;

    // third_it_prev->left = nullptr;
      
    // Do not edit the return statement of this method.
    return *this;
  }
};


int main() {
  BST * myBST = new BST(10);
  myBST->insert(5);
  myBST->insert(15);

  assert(myBST->contains(10) == true);
  assert(myBST->contains(5) == true);
  assert(myBST->contains(15) == true);

  myBST->remove(10);
  myBST->remove(5);
  myBST->remove(15);


  assert(myBST->contains(10) == false);
  assert(myBST->contains(5) == false);
  assert(myBST->contains(15) == true);

  // myBST->contains(10);
  // myBST->contains(5);
  // myBST->contains(15);


}