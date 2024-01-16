#include <vector>
using namespace std;

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
};

void inOrderTraverse(BST* tree, vector<int>& array) {
  // Write your code here.
  if (tree->left != nullptr){
    inOrderTraverse(tree->left,array);
  }
  array.push_back(tree->value);
  // Write your code here.
  if (tree->right != nullptr){
    inOrderTraverse(tree->right,array);
  }
  
}

void preOrderTraverse(BST* tree, vector<int>& array) {
  // Write your code here.
    // Write your code here.
  array.push_back(tree->value);
  if (tree->left != nullptr){
    preOrderTraverse(tree->left,array);
  }
  // Write your code here.
  if (tree->right != nullptr){
    preOrderTraverse(tree->right,array);
  }
}

void postOrderTraverse(BST* tree, vector<int>& array) {
  // Write your code here.
    // Write your code here.
  if (tree->left != nullptr){
    postOrderTraverse(tree->left,array);
  }
  // Write your code here.
  if (tree->right != nullptr){
    postOrderTraverse(tree->right,array);
  }
  array.push_back(tree->value);
}


int main() {
  
}