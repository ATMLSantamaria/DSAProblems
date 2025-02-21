#include "z_Auxiliar.h"
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

  void insert(int value) {
    BinaryTree* current = this;
    while (true) {
      if (value < current->value) {
        if (current->left == nullptr) {
          current->left = new BinaryTree(value);
          break;
        } else {
          current = current->left;
        }
      } else {
        if (current->right == nullptr) {
          current->right = new BinaryTree(value);
          break;
        } else {
          current = current->right;
        }
      }
    }
  }
};

BinaryTree* createTreeWith20Elements() {
  BinaryTree* root = new BinaryTree(10);
  int elements[] = {5, 15, 3, 7, 13, 17, 2, 4, 6, 8, 12, 14, 16, 18, 1, 9, 11, 19, 20};
  for (int element : elements) {
    root->insert(element);
  }
  return root;
}


void branchSumsHelper(BinaryTree* root,int sum,std::vector<int> & res) {
  if (root == nullptr) {
    return;
  }
  sum += root->value;
  if (root->left == nullptr && root->right == nullptr) {
    res.push_back(sum);
    return;
  }
  
  branchSumsHelper(root->left,sum,res);
  branchSumsHelper(root->right,sum,res);
}

vector<int> branchSums(BinaryTree* root) {
  // Write your code here.
  std::vector<int> res;
  branchSumsHelper(root,0,res);
  
  return res;
}

int main() {

  BinaryTree* myTree = createTreeWith20Elements() ;
  std::vector<int> res;
  res = branchSums(myTree);

  for (auto &i : res) {
    std::cout << i << " , ";
  }
  std::cout <<std::endl;


}