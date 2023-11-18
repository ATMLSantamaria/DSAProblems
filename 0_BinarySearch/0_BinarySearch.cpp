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

}

//In C++ a functor would be better but this is simple enough so it does not matter.
//I use this function to test the different implementation sof BinarySearch
void test_to_function(int (* function_pointer_to_test)(std::vector<int> &,int,int,int),std::vector<int> & myInput_) {
  
  //This will check that the tested function find the appropiate index for each element of an array.
  //Useful for spot edge errors in small samples. 
  for (size_t i = 0; i < myInput_.size();++i) {
    assert(function_pointer_to_test(myInput_,myInput_[i],0,myInput_.size()-1) == i);
  }
}

int main() {
  std::vector<int> myInput_ = {0,4,6,22,35,65,70,77,79,80};

  int (*functionRecursive)(std::vector<int> &,int,int,int) = &RecursiveBinarySearch;

  test_to_function(functionRecursive,myInput_);

}