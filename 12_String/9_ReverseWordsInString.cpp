#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string reverseWordsInString(string str) {
  // First reverse full string
  std::reverse(str.begin(),str.end());
  cout << str <<endl;
  // Now reverse each word in the resulting string
  auto slowIt = str.begin();
  for (auto it = str.begin();it < str.end();++it) {
    char tracking = *it;
    if ( (it+1) == str.end() || *(it+1) == ' ') { // do not use checks against \0 in c++ strings, only in C. Better the .end()
      std::reverse(slowIt,it+1);
      it++;
      slowIt=it;
    }
    char tmp = *it;
    while(it != str.end() && *it == ' ') {
      it++;
      slowIt++;
    }
  }
  return str;
}


int main() {
  string target = "has a ";

  cout << reverseWordsInString(target) << endl;
}