#pragma once


#include <cmath>
#include <algorithm>
#include <cassert>
#include <iostream>

#include <queue>


template <typename TreeType>
TreeType * createTree() {
  BinaryTreeTypeTree* root = new TreeType(10);
  int elements[] = {5, 15, 3, 7, 13, 17, 2, 4, 6, 8, 12, 14, 16, 18, 1, 9, 11, 19, 20};
  for (int element : elements) {
    root->insert(element);
  }
  return root;
}