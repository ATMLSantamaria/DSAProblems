#include <cmath>
#include <algorithm>
#include <cassert>
#include <iostream>

#include <queue>

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val){
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST& insert(int val) {
    // Write your code here.
    BST * iterator = this;
    BST * iterator_prev = this;
    while (iterator != nullptr) {
      if (val < iterator->value) {
        iterator_prev = iterator;
        iterator = iterator->left;
      } else {
        iterator_prev = iterator;
        iterator = iterator->right;
      }
    }
    if (val < iterator_prev->value) {
      iterator_prev->left = new BST(val);
    } else {
      iterator_prev->right = new BST(val);
    }
    return *this;
  }
};



//This algorithm is partially iterative and partially recursive.
//Average Complexity T O(log N). S O(log N) with N being number of thement in tree
int findClosestValueInBst(BST* tree, int target) {
  //Basically we need to compare with value, r->value and l->value
  //if value is the closest to target, then we return value
  //If value is closest to the right, we continue searching there
  //If value is closest to the left, we continue searching there.
  //By the definition of the BST if a value is closer to right, the

  BST* current = tree;
  int closest = current->value;
  int diff_to_r; // = abs(target - current->right->value);
  int diff_to_l; // = abs(target - current->left->value);

  
  while(current != nullptr) {

    closest = (abs(current->value - target) < abs(closest - target)) ? current->value : closest;

    if (current->left == nullptr && current->right == nullptr) { //2 childs nullptr
      return closest;
    }
    else if (current->left == nullptr) { //1 childs nullptr
      current = current->right; //this perform extra computations in certain circumstances
    }
    else if (current->right == nullptr) { //1 childs nullptr
      current = current->left; //this perform extra computations in certain circumstances
    }
    else { //both childs exist
      diff_to_r = abs(target - current->right->value);
      diff_to_l = abs(target - current->left->value);

      // 1 - Target mas cerca de Left. 
      if (diff_to_l < diff_to_r) {
        int closest_right = findClosestValueInBst(current->right,target);
        int closest_left = findClosestValueInBst(current->left,target);
        if (abs(closest_left - target) < abs(closest_right - target)) {
          return (abs(closest - target) < abs(closest_left - target)) ? closest : closest_left; 
        } else {
          return (abs(closest - target) < abs(closest_right - target)) ? closest : closest_right; 
        }
        //current = current->left;
      }  
      else if (diff_to_l > diff_to_r) {
        current = current->right;    
      }
      else {
        current = current->right;
      }
    }
  }
  return closest;
}

void printLevelOrder(BST* root);
BST * createTree();
int main() {

  
  BST * myTree = createTree();

  printLevelOrder(myTree);


  int res = findClosestValueInBst(myTree,2000);

  std::cout << res << std::endl;

  assert(res == 1001);

  

}



BST * createTree() {
  BST * myBST = new BST(100);
  myBST->insert( 502);
  myBST->insert(55000);
  myBST->insert(1001);
  myBST->insert(4500);
  myBST->insert(204);
  myBST->insert(205);
  myBST->insert(207);
  myBST->insert(208);

  myBST->insert(206);
  myBST->insert(203);
  myBST->insert(5);
  myBST->insert(15);
  myBST->insert(22);
  myBST->insert(57);

  myBST->insert(60);
  myBST->insert(5);
  myBST->insert(2);
  myBST->insert(3);
  myBST->insert(1);

  myBST->insert(1);
  myBST->insert(1);
  myBST->insert(1);
  myBST->insert(1);
  myBST->insert(-51);
  myBST->insert(-403);

}

using namespace std;

void printLevelOrder(BST* root) {
  if (root == nullptr) return;

  queue<BST*> q;
  q.push(root);

  while (!q.empty()) {
    int levelSize = q.size();

    for (int i = 0; i < levelSize; i++) {
      BST* current = q.front();
      q.pop();
      cout << current->value << " ";

      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
      }
    }
    cout << endl;
  }
}
