#include <algorithm>
#include "z_Auxiliar.h"


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

int computeHeight(BinaryTree * node,int & maxDiameter) {
  if (node == nullptr) {
    return 0;
  }
  int maxDiameterOriginal = maxDiameter;
  int height_l = computeHeight(node->left,maxDiameter);
  int maxDiameter_left = maxDiameter;
  int height_r = computeHeight(node->right,maxDiameter);
  int maxDiameter_right = maxDiameter;

  if ((height_l + height_r) > maxDiameter) {
    maxDiameter = std::max<int>({height_l + height_r,maxDiameter_left,maxDiameter_right,maxDiameterOriginal});
  }
  
  return (height_l >= height_r) ? height_l + 1 : height_r + 1;
}

int binaryTreeDiameterAux(BinaryTree* tree) {

  if (tree == nullptr) {
    return 0;
  }

  int holder=0;
  
  int maxDiameterNode = std::max<int>({
              binaryTreeDiameterAux(tree->left),
              binaryTreeDiameterAux(tree->right),
              computeHeight(tree->left,holder)+computeHeight(tree->right,holder)}
              );
  
  return maxDiameterNode;
            
  
}

int binaryTreeDiameter(BinaryTree* tree) {
  // Write your code here.
  int maxDiameter = 0;
  computeHeight(tree,maxDiameter);
  //binaryTreeDiameterAux(tree);
  return maxDiameter;
}
int main() {

  BinaryTree*  myTree = createTreeAux<BinaryTree>();

  printLevelOrder(myTree);
  std::cout << std::endl;

  std::cout << "Max Diameter = " << binaryTreeDiameter(myTree) <<std::endl;

}
