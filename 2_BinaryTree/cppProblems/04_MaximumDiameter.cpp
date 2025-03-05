#include <algorithm>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};
int getInfo(BinaryTree * tree,int & maxDiameter);
int binaryTreeDiameter(BinaryTree* tree) {
  // Write your code here.
  int maxDiameter = 0;
  getInfo(tree,maxDiameter);
  return maxDiameter;
}

int getInfo(BinaryTree * tree,int & maxDiameter) {
  if (tree == nullptr) {
    return 0;
  }
  // Propagate to correct nodes
  int deepLeft = getInfo(tree->left,maxDiameter);
  int deepRight =  getInfo(tree->right,maxDiameter);

  // Compute max diameter
  maxDiameter = std::max(deepLeft+deepRight,maxDiameter);
  // Return the maximum depth from this subnode, adding one, since returning we are ascending
  return 1 + std::max(deepLeft,deepRight);
}