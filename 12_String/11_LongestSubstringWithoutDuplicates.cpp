#include <unordered_map>
#include <string>
using namespace std;

// This is a variation of a classic sliding window problem
string longestSubstringWithoutDuplication(string str) {
  int left = 0;
  
  int maxLen = 0;
  int minLeft = 0;

  unordered_map<char,int> indexMap;

  for (int right = 0;right < str.size();++right) {

    char currentCh = str[right];

    // Move until finding a duplicate
    while (right < str.size() && indexMap.count(currentCh) == 0) {
      // Update dictionary
      indexMap[currentCh] = right;
      
      // Move forward
      right++;
      if (right == str.size()) {
        break; // avoid problematic access out of bounds
      }
      currentCh = str[right];
    }
    // This while loop should break when the duplicate has been found

    // When a duplicate is find. Compare length with current maxLen. Update the current optimum values.
    if (right - left > maxLen) {
      minLeft = left;
      maxLen = right - left;
    }

    // Update left iterator and bring it to element after the first onw that was repeated.
    // And while bringing the left forward, erase those chars from the map
    int newLeft = indexMap[currentCh] + 1;
    while (left <  newLeft) {
      indexMap.erase(str[left]);
      left++;
    }

    indexMap[currentCh] = right;
    
  }

  return str.substr(minLeft,maxLen);
  
}