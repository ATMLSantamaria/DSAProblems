#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> BubbleSort(vector<int> array) {
  
    // traverse from left and compare adjacent elements and the higher one is placed at right side. 
    // In this way, the largest element is moved to the rightmost end at first. 
      // This process is then continued to find the second largest and place it and so on until the data is sorted.
  int to_swap = 0;
  for (auto & i : array) {
    for (auto &j : array) {
      if (j > i) {
        to_swap = i;
        i = j;
        j = to_swap;
      }
    }
  }
  return array;  
}

int main() {
  std::vector<int> target = {4,6,44,5,1,2,4,3,2,1,66,55,44,33,-1};

  std::vector<int> res = BubbleSort(target);

  std::for_each(res.begin(),res.end(),[](int & element){std::cout << element << " ";});

}