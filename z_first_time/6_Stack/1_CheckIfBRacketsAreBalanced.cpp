#include <stack>
#include <string>
#include <cassert>
#include <unordered_map>

using namespace std;


bool BalancedBrackets(string str) {
  std::stack<char> track_brackets;
  std::unordered_map<char,char> myPairs;

  myPairs[')'] = '(';
  myPairs[']'] = '[';
  myPairs['}'] = '{';

  char to_check = 0;
  
  for (auto i : str) {
    if (i=='(' || i == '[' || i == '{') {
      track_brackets.push(i);
    }

    if (i==')' || i == ']' || i == '}') {
      if (track_brackets.empty()) {
        return false;
      }
      
      to_check = track_brackets.top(); //( or { or [ 
      track_brackets.pop();
      
      if (myPairs[i] != to_check) {
        return false;
      }
    }
  }
  if (!track_brackets.empty()) {
    return false;
  }
  return true;
}

int main() {
  std::string target1 = "()()([dd{}])";
  std::string target2 = "()()([dd{}])(";

  assert(BalancedBrackets(target1) == true);
  assert(BalancedBrackets(target2) == false);


}