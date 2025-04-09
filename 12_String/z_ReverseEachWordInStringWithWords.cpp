#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string reverseEachWordInAString(string str) {
  auto slowIt = str.begin();
  for (auto it = str.begin();it<str.end();++it) {
    if (*(it) == ' ' || it == str.end()) {
      std::reverse(slowIt,it);
      slowIt=it;
    }
    while (it != str.end() && *it == ' ') {
      it++;
      slowIt++;
    }
  }
  return str;
}

int main() {
  string target = "ABC         12345         ANNA        TORO   ";
  string target2 = "a has";
  cout << reverseEachWordInAString(target) << endl;
  cout << reverseEachWordInAString(target2) << endl;

}
