#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

// The trick is clearly with the negative numbers
// [-8,-2,0,1,3,6,9] -> [0,1,4,9,36,64,81]

// In any moment the next biggest number will be either the minimum negative or the maximum positive

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
  vector<int>solution(array.size());
  int left = 0, right = array.size() - 1;
  for (auto it = solution.rbegin();it != solution.rend();++it) {

    if (abs(array[left]) > abs(array[right])) {
      *it = pow(array[left],2);
      left++;
    } else {
      *it = pow(array[right],2);
      right--;
    }
    
  } 
  
  return solution;
}

int main() {
  std::vector<int> test = {-8,-2,0,1,3,6,9};
  std::vector<int> solution = sortedSquaredArray(test);
  for (auto i : solution) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}