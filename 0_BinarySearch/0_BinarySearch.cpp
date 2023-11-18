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



int main() {
  std::vector<int> myInput_ = {0,4,6,22,35,65,70,77,79,80};

  int existing_target = 79;
  int non_existing_target = 100;


  assert(RecursiveBinarySearch(myInput_,existing_target,0,myInput_.size()-1) == 8);
  assert(RecursiveBinarySearch(myInput_,non_existing_target,0,myInput_.size()-1) == -1);
  

  for (size_t i = 0; i < myInput_.size();++i) {
    assert(RecursiveBinarySearch(myInput_,myInput_[i],0,myInput_.size()-1) == i);
    assert(BinarySearch(myInput_,myInput_[i]) == i);
  }
}