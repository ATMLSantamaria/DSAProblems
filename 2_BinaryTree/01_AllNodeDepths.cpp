using namespace std;

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

int deepFirstSearchTraversal(BinaryTree * root,int depth = 0);
int nodeDepths(BinaryTree* root) {
  // Write your code here.
  int solution = 0;
  return deepFirstSearchTraversal(root);

}

int deepFirstSearchTraversal(BinaryTree* root,int depth) {
  if (root == nullptr) {
    return 0;
  }
  return depth + deepFirstSearchTraversal(root->left,depth+1) + deepFirstSearchTraversal(root->right,depth+1);
}
