#include <vector>
#include <iostream>
using namespace std;

void helper (int i, vector<int> & arr,vector<vector<int>> & perms) {
  if (i == (arr.size() - 1)) {
    perms.push_back(arr);
  } else {
    for (int j = i;j < arr.size();++j) {
      std::swap(arr[i],arr[j]);
      helper(i+1,arr,perms);
      std::swap(arr[i],arr[j]);
    }
  }
}

vector<vector<int>> getPermutations(vector<int> array) {
  // Write your code here.
  vector<vector<int>> permutations;
  helper(0,array,permutations);
  return permutations;
}

int main() {
  std::vector<int> toTest = {1,2,3};
  vector<vector<int>> res = getPermutations(toTest);
  for (auto & i : res) {
    std::cout << "{";
    for (auto & j : i) {
      std::cout << j << " ";
    }
    std::cout << "}\n";  
  }
}
