#include <vector>
#include <algorithm>
using namespace std;
// 12 3 1 2 -6 5 -8 6

// targetSum = 0

// We use technique of 2 pointers after sorting the array.
// We iterate in the array and use 2 pointers to left and right of the number. Compare with target and update left or right as needed

// This algorithm run in O(n^2) time and O(n) space
vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  vector<vector<int>> solution;
  // Sort
  std::sort(array.begin(),array.end());

  int left = 0;
  int right = 0;
  int currentNum = 0;
  int currentSum = 0;
  
  //iterate in the array excluding the 2 ends since they cant have a number to their respective side
  for (int i = 1; i < array.size() - 1;++i) {
    currentNum = array[i];

    left = i - 1;
    right = i + 1;

    currentSum = currentNum + array[left] + array[right];

    // Now compare currentSum with left and right and iterate as needed
    while (left >=0 && right <= array.size() - 1) {
      if (currentSum > targetSum) {
        left--; // we need to do left smaller to make the sum smaller
      } else if ( currentSum < targetSum) {
        right++; // we need to do right bigger to make the sum bigger
      } else {
        solution.push_back({array[left],array[i],array[right]});
        right++;
        left--;
      }
      currentSum = currentNum + array[left] + array[right];
    }
  }
  std::sort(solution.begin(),solution.end());
  return solution;
}