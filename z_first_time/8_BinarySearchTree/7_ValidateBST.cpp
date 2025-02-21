#include <climits>
#include <algorithm>
#include <cassert>
class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val) :value(val),left(nullptr), right(nullptr) {};
  BST& insert(int val)  {
    if (val < value) {
        if (left == nullptr) {
            left = new BST(val);
        } else {
            left->insert(val);
        }
    } else {
        if (right == nullptr) {
            right = new BST(val);
        } else {
            right->insert(val);
        }
    }
    return *this;
  };
};

//bool validate_elements;

//min <= val < max
bool validateBstHelper(BST* tree, int minVal,int maxVal);

bool validateBst(BST* tree) {

  return validateBstHelper(tree,INT_MIN,INT_MAX);
  
}

bool validateBstHelper(BST* tree, int minVal,int maxVal) {
  bool res = true;
  int this_value = tree->value;
  //int min_val = std::min(minVal,tree->val);

  if (this_value >= maxVal || this_value < minVal) {
    return false;
  }
  //Protect againt nullptr
  if (tree->left == nullptr && tree->right == nullptr) {
    return res;
  }
  if (tree->left == nullptr) {
    return validateBstHelper(tree->right,this_value,maxVal);
  }
  if (tree->right == nullptr) {
    return validateBstHelper(tree->left,minVal,this_value);
  }
  // All left most element of the right list has to be validated too
  return validateBstHelper(tree->right,this_value,maxVal) && validateBstHelper(tree->left,minVal,this_value);
}

int main() {

  BST bst(50);
  bst.insert(30).insert(20).insert(40).insert(70).insert(60).insert(80).insert(90).insert(85).insert(100).insert(55);

  assert(validateBst(&bst));

  bst.left->value=1000;
  //Now the bst is not a bst anymore
  assert(!validateBst(&bst));

}