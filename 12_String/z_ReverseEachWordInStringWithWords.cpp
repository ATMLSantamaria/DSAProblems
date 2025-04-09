#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string reverseEachWordInAString(string str) {
  auto slowIt = str.begin();
  for (auto it = str.begin();it<str.end();++it) {
    if (*(it+1) == ' ' || *(it+1) == '\0') {
      std::reverse(slowIt,it+1);
      it++;
      slowIt=it;
    }
    while (*it == ' ') {
      it++;
      slowIt++;
    }
  }
  return str;
}

int main() {
  string target = "ABC         12345         ANNA        TORO   ";
  cout << reverseEachWordInAString(target) << endl;
}
