#include <vector>
#include "z_Auxiliar.h"
using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value):value(value),left(nullptr),right(nullptr) {};
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree* tree) {
  if (tree == nullptr) {
    return;
  }
  if (tree->left == nullptr && tree->right == nullptr) {
    return;
  }
  BinaryTree* to_swap;
  to_swap = tree->left;
  tree->left = tree->right;
  tree->right = to_swap;

  invertBinaryTree(tree->left);
  invertBinaryTree(tree->right);
}

int main() {
  BinaryTree * myTree = createTreeAux<BinaryTree>();

  printLevelOrder<BinaryTree>(myTree);

  std::cout << std::endl;

  invertBinaryTree(myTree);

  printLevelOrder<BinaryTree>(myTree);

}