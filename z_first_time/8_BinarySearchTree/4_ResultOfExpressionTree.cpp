#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};


// Complexity T O(N) S O(N) due to the recurssion. Where N is the number of elements
int evaluateExpressionTree(BinaryTree* tree) {
  if (tree->value == -1) {
    return evaluateExpressionTree(tree->left) + evaluateExpressionTree(tree->right);
  }
  if (tree->value == -2) {
    return evaluateExpressionTree(tree->left) - evaluateExpressionTree(tree->right);
  }
  if (tree->value == -3) {
    if (evaluateExpressionTree(tree->right) == 0) {  std::abort();}
    return evaluateExpressionTree(tree->left) / evaluateExpressionTree(tree->right);
  }
  if (tree->value == -4) {
    return evaluateExpressionTree(tree->left) * evaluateExpressionTree(tree->right);
  } else {
    return tree->value;
  }
}

int main() {
  BinaryTree * root = new BinaryTree(-1);

  BinaryTree * l_1 = new BinaryTree(-4);
  BinaryTree * r_1 = new BinaryTree(100);

  BinaryTree * l_l_1 = new BinaryTree(5);
  BinaryTree * l_r_1 = new BinaryTree(20);

  root->left =l_1;
  root->right = r_1;

  l_1->left = l_l_1;
  l_1->right = l_r_1;


  int res = evaluateExpressionTree(root);
  assert(200 == res);



}