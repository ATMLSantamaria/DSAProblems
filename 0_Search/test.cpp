#include "0_BinarySearch.hpp"


//In C++ a functor would be better but this is simple enough so it does not matter.
//I use this function to test the different implementation sof BinarySearch
void test_to_function(int (* function_pointer_to_test)(std::vector<int> &,int,int,int),std::vector<int> & myInput_, int element_not_in_array) {
  
  //This will check that the tested function find the appropiate index for each element of an array.
  //Useful for spot edge errors in small samples. 
  for (size_t i = 0; i < myInput_.size();++i) {
    assert(function_pointer_to_test(myInput_,myInput_[i],0,myInput_.size()-1) == i);
  }

  assert(function_pointer_to_test(myInput_,element_not_in_array,0,myInput_.size()-1) == -1);
}

int main() {
  std::vector<int> myInput_ = {0,4,6,22,35,65,70,77,79,80};

  int (*functionRecursive)(std::vector<int> &,int,int,int) = &RecursiveBinarySearch;
  
  int (*functionIterative)(std::vector<int> &,int,int,int) = &IterativeBinarySearch;

  test_to_function(functionRecursive,myInput_,10000);
  test_to_function(functionIterative,myInput_,10000);


}