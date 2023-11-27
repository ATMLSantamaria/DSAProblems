#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

//  maxSum[0]=array[0]     maxSum[1] = array[1]

//  maxSum[i] = max(maxSum[i-1],maxSum[i-2]+array[i])

//Solution in T O(N) and S O(N) where N is the number of elements in the array
int maxSubsetSumNoAdjacent(vector<int> array) {

  if (array.empty()) {
    return 0;
  } 
  if (array.size() == 1) {
    return array[0];
  }
  if (array.size() == 2) {
    return std::max(array[0],array[1]);
  }

  std::vector<int> res(array.size());

  res[0] = array[0];
  res[1] = array[1] > array[0] ? array[1] : array[0];
  
  for (int i = 2;i < array.size();++i) {
    res[i] = std::max(res[i -1],res[i - 2] + array[i]);
  }
  
  return res.back();
}

int main() {
  std::vector<int> target = {75,105,120,75,90,135};

}