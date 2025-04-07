#include <vector>
using namespace std;

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};
void minHeightBstHelper(const vector<int> & array,BST* tree,int left, int right);
BST* minHeightBst(vector<int> array) {
  // For the BST to have minimum height it must be balanced.
  // Since array is ordered I can use this to my advantage.

  int left = 0;
  int right = array.size() - 1;

  int middle = (right + left) / 2;

  BST * myTree = new BST(array[middle]);

  //left
  minHeightBstHelper(array,myTree,left,middle - 1);
  //right
  minHeightBstHelper(array,myTree,middle + 1,right);
  
  return myTree;
}

void minHeightBstHelper(const vector<int> & array,BST* tree,int left, int right) {
  
  // Base case to finish recursion
  if (left > right) {
    return;
  }  
   
  // Find element in the middle
  int middle = left + (right - left) / 2; //Safe in case the left and right are close to MAX INT

  tree->insert(array[middle]);
  // left
  minHeightBstHelper(array,tree,left,middle - 1);

  //right
  minHeightBstHelper(array,tree,middle + 1, right);

}

