using namespace std;

// This is the class of the input root. Do not edit it.
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

void helper(BinaryTree * root, vector<int>&solution,int currentSum);
vector<int> branchSums(BinaryTree* root) {
  vector<int> solution;
  helper(root,solution,0);
  return solution;
}

void helper(BinaryTree * root,vector<int>&solution,int currentSum) {
  if (root == nullptr){
    return;
  }
  
  currentSum = currentSum + root->value;
    
  if (root->left == nullptr && root->right == nullptr) {
    // currentSum = currentSum + root->value
    solution.push_back(currentSum);
    return;
  }
  
  helper(root->left,solution,currentSum);
  helper(root->right,solution,currentSum); 
}