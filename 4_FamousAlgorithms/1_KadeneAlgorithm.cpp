#include <vector>
using namespace std;

// For each index, the maximum sum of a subarray ending at the index is:
// 1 - the maximum sum for the previous sub array PLUS that number
// 2 - That number

// In each iteration keep track

// O(n) time | O(1) space
int kadanesAlgorithm(vector<int> array) {

  int maxSum = array[0];

  int runningSum = array[0];

  for (int i = 1; i < array.size();++i) {

    runningSum = std::max(runningSum + array[i],array[i]);

    maxSum = std::max(runningSum,maxSum);
    
  }
  
  return maxSum;

}
