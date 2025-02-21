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

  BST& remove(int val,BST * parent = nullptr) {
    
    BST * current = this;

    //0 - Search for Node to be removed
    //    Keep a pointer to the parent of that Node
    while (val != current->value) {
      parent = current;
      if (val < current->value) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    // 1 -  We try to remove an stand alone node the method simply returns
    if (current->left == nullptr && current->right == nullptr && parent == nullptr) {//this makes me unable to delete 15
      return *this;
    }
    if (current->left == nullptr && current->right == nullptr && parent != nullptr) {
      if (parent->left == current) {
        parent->left = nullptr;
      }
      if (parent->right == current) {
        parent->right = nullptr;
      }
    }

    // 2 - Case with 2 subtrees
    if (current->left != nullptr && current->right != nullptr) {
      //Replace the value of current by the value of the leftmost element of its right tree to keep the tree as a BST
      current->value = current->right->getMinVal();
      //Remove the node from where we tool the value
      current->right->remove(current->value,current);
      return *this;
    }

    //3 - Case with parent == null and 1 subtree; //We already eliminated the case with 2 null childs
    if (parent == nullptr) {
      if (current->left != nullptr) {
        current->value = current->left->value;
        current->right = current->left->right;
        current->left = current->left->left;
        return *this;

      } else if (current->right != nullptr){
        current->value = current->right->value;
        current->right = current->right->right;
        current->left = current->right->left;
        return *this;
      } else {
        current->value = 0;
        return *this;
      }
    }

    //4 - Case with only one subtree and Parent != null
    if (parent->left == current) { //this comparison is more subtle than my original bool updated while searching for current
      parent->left = (current->left != nullptr) ? current->left : current->right;
      return *this;
    }
    if (parent->right == current) {
      parent->right = (current->left != nullptr) ? current->left : current->right;
      return *this;
    }


    return *this;
  }


  int getMinVal() {
    BST * current = this;
    //Just travel left in the direction of the minimum values until arrive to the end
    while (current->left != nullptr) {
      current = current->left;
    }
    return current->value;
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