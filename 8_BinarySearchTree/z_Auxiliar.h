#pragma once


#include <cmath>
#include <algorithm>
#include <cassert>
#include <iostream>

#include <queue>


template<typename TreeType>
void InsertIn(int value,TreeType *root);


template <typename TreeType>
TreeType * createTreeAux() {
  TreeType* root = new TreeType(10);
  int elements[] = {5, 15, 3, 7, 13, 17, 2, 4, 6, 8, 12, 14, 16, 18, 1, 9, 11, 19, 20};
  for (int element : elements) {
    InsertIn(element,root);
  }
  return root;
}

template<typename TreeType>
void InsertIn(int value,TreeType *root) {
    TreeType* current = root;
    while (true) {
      if (value < current->value) {
        if (current->left == nullptr) {
          current->left = new TreeType(value);
          break;
        } else {
          current = current->left;
        }
      } else {
        if (current->right == nullptr) {
          current->right = new TreeType(value);
          break;
        } else {
          current = current->right;
        }
      }
    }
}

template<typename TreeType>
void printLevelOrder(TreeType* root) {
  if (root == nullptr) return;

  std::queue<TreeType*> q;
  q.push(root);

  while (!q.empty()) {
    int levelSize = q.size();

    for (int i = 0; i < levelSize; i++) {
      TreeType* current = q.front();
      q.pop();
      std::cout << current->value << " ";

      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
      }
    }
    std::cout << std::endl;
  }
}
