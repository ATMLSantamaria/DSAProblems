#ifndef DSA_BINARYSEARCH_0_
#define DSA_BINARYSEARCH_0_
// Problem Binary Search
// Input Vector
// Return index or -1


#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

int RecursiveBinarySearch(vector<int> & array, int target,int left,int right);

int BinarySearch(vector<int> array, int target) {
  // Write your code here.
  return RecursiveBinarySearch(array,target,0,array.size()-1);
}

//Passing by reference the vector the Space Complexity is kept at O(1)
int RecursiveBinarySearch(vector<int> & array, int target,int left,int right) {

  //Base Case -> When to break the recursion
  if (left > right) {
    return -1;
  }

  //Find Middle Point
  int m = (left + right) / 2;

  //Check if we found solution
  if (array[m] == target ) {
    return m;
  } else if (target < array[m]) {
    return RecursiveBinarySearch(array,target,left,m-1);
  } else {
    return RecursiveBinarySearch(array,target,m+1,right);
  }
}

int IterativeBinarySearch(std::vector<int> &array,int target, int left, int right) {

  //Base case is left>right
  while(left <= right) {
    // 1 find middle
    int m = (left + right) / 2;
    // Check if result
    if (array[m] == target) {
      return m;
    } else if (target < array[m]) {
      left = left; //unnecesary
      right = m - 1 ;
    } else {
      left = m + 1;
      right = right;
    }
  }
  return -1;

}

#endif