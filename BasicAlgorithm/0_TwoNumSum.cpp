#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;



//Basic Version of the algorithm running in O(n2)
vector<int> twoNumberSumBasic(vector<int> array, int targetSum) {
  // Write your code here.
  int a = 0;
  int b = 0;
  
  //a + b = sum
  //sum - a = b
  for (size_t i = 0;i < array.size();++i) {
    a = array[i];
    b = targetSum - a;
    for (size_t j = i + 1;j < array.size();++j) {
      if (b == array[j]) {
        return {a,b};
      }
    }
  }
  return {};
}

//Better version. Try to run in O(n)
//This run in O(2n) so basically O(n), but there is an even better way
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  int a = 0;
  int b = 0;
  //a + b = sum
  //sum - a = b
  //The map contains values as keys and the indices as values
  std::unordered_map<std::string,uint64_t> myMap_;
  int index_ = 0;
  for (auto &i : array) {
    myMap_[std::to_string(i)] = index_;
    ++index_;
  }

  for (uint64_t i = 0; i < array.size();++i) {
    a = array[i];
    b = targetSum - a;

    //Search for b in the keys of the map, taking care that the index of b is different from i
    auto it = myMap_.find(std::to_string(b));
    if (it != myMap_.end() && it->second != i) {
      return {a,b};
    }
  }  
  return {};
}


vector<int> twoNumberSumBetter(vector<int> array, int targetSum) {
  int a = 0;
  int b = 0;
  //a + b = sum
  //sum - a = b
  //The map contains values as keys and the indices as values
  std::unordered_map<int,uint64_t> myMap_;

  for (uint64_t i = 0; i < array.size();++i) {
    a = array[i];
    b = targetSum - a;

    //Search for b in the keys of the map, taking care that the index of b is different from i
    auto it = myMap_.find(b);
    if (it == myMap_.end()) {
      myMap_[a]=i;
    } else {
      return {a,b};
    }
  }  
  return {};
}


int main() {
  std::vector<int> test = {1,5,-1,8,11,32,16};
  int targetSum = 10;

  std::vector<int> result = twoNumberSumBetter(test,targetSum);

  assert(result[0] == 11);
  assert(result[1] == -1);


}
