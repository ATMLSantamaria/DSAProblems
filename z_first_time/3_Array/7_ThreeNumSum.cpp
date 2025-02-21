#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//Find all the possible combinations of 3 numbers whose summa give targetSum as result

//1 Iterate in Array through all elements.
//2 For each element we calculate X as targetSum - element
//3 We compute the sum of the 2 numbers that result in X

//Complexity Time O(n^2) Space O(n)
vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  //1 Sort
  std::vector<std::vector<int>> res;
  std::sort(array.begin(),array.end());
  int L = 0;
  int R = 0;
  int local_sum = 0;
  
  // Iterate through array
  for (int i = 0;i < array.size();++i) {
    int X = targetSum - array[i];
    L = i + 1;
    R = array.size() - 1;
    while (L < R) {
      local_sum = array[L] + array[R];
      if (local_sum > X) {
        R--;
      } else if (local_sum < X) {
        L++;
      } else {
        res.push_back({array[i],array[L],array[R]});
        R--;
      }
    }
  }
  
  return res;
}

int main() {

  std::vector<int> target = {12, 3, 1, 2, -6, 5, -8, 6};

  vector<vector<int>> res = threeNumberSum(target,0);

  for (auto &i : res){
    for (auto &j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}