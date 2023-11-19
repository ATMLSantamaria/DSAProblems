#include <vector>
#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
  int index = 0;
  if (sequence.size() > array.size()) {
    return false;
  }
  for (uint64_t i = 0; i < array.size();++i) {
    if (sequence[index] == array[i]) {
      if (index == sequence.size()-1) {
        return true;
      }
      index++;
    }  
  }
  return false;
}



int main() {
  std::vector<int> array = {5, 1, 22, 25, 6, -1, 8, 10};
  std::vector<int> sequence = {1, 6, -1};
  
  assert(isValidSubsequence(array,sequence));
}

