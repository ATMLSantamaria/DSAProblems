using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

int evaluateExpressionTree(BinaryTree* tree) {
  if (tree == nullptr) {
    return 0;
  }
  if (tree->left == nullptr and tree->right == nullptr) {
    return tree->value;
  }
  if (tree->value == -1) {
    return evaluateExpressionTree(tree->left) + evaluateExpressionTree(tree->right);
  }

  if (tree->value == -2) {
    return evaluateExpressionTree(tree->left) - evaluateExpressionTree(tree->right);
  }

  if (tree->value == -3) {
    return evaluateExpressionTree(tree->left) / evaluateExpressionTree(tree->right);
  }

  if (tree->value == -4) {
    return evaluateExpressionTree(tree->left) * evaluateExpressionTree(tree->right);
  }
  
}
