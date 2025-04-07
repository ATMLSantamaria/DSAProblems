#include <utility>
#include <string>
#include <iostream>

using namespace std;

std::pair<int,int> expandOdd(string & str, int center) {
  int left = center;
  int right = center;
  //Expand and check if Palindrome
  while(left > 0 && right < str.size() - 1) {
    // If palindrome expand
    if(str[left-1] == str[right+1]) {
      left--;
      right++;
    } else {
      //if no palindrome break
      break;
    }
  }
  return make_pair(left,right);
}

std::pair<int,int> expandEven(string & str, int firstCenter) {
  int left = firstCenter;
  int right = firstCenter + 1;

  if(str[left] != str[right]) {
    return make_pair(left,left);
  }

  while (left > 0 && right < str.size() - 1) {
    if (str[left-1] == str[right+1]) {
      left--;
      right++;
    } else {
      break;
    }
  }
  return make_pair(left,right);
  
}


string longestPalindromicSubstring(string str) {
  int minLeft = 0;
  int maxRight = 0;
  int maxLen = 1;

  for (int i = 0; i < str.size();i++) {
    auto check = expandOdd(str,i);
    if (check.second - check.first + 1 > maxLen) {
      minLeft = check.first;
      maxRight = check.second;
      maxLen = maxRight - minLeft + 1;
    }
    if (str.size() > 1){   
      check = expandEven(str,i);
      if (check.second - check.first + 1 > maxLen) {
        minLeft = check.first;
        maxRight = check.second;
        maxLen = maxRight - minLeft + 1;
      }
    }
      
  }

  string sol;
  for (int i = minLeft; i <= maxRight;i++) {
    sol += str[i];
  }
  return sol;
  
}

int main() {
  string target = "fhgnkdhabcdeffedcbtkj";

  cout << longestPalindromicSubstring(target) << endl;
}