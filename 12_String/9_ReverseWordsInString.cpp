#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string reverseWordsInString(string str) {
  // First reverse full string
  std::reverse(str.begin(),str.end());

  // Now reverse each word in the resulting string using slow and fast iterator
  auto slowIt = str.begin();
  
  for (auto it = str.begin();it < str.end();++it) {
    // If the end of the string is reached or a space is reached reverse the word (the last word)
    if ( (it+1) == str.end() || *(it+1) == ' ') { // do not use checks against \0 in c++ strings, only in C. Better the .end()
      std::reverse(slowIt,it+1);
      // Move it forward
      it++;
      // Reset slowIt
      slowIt=it;
    }

    // If we are in a space move both iterators unreach the beginning of the new word or the end of the string
    while(it != str.end() && *it == ' ') { // avoid the while loop to reach str.end()
      it++;
      slowIt=it;
    }
  }
  return str;
}


int main() {
  string target = "has a ";
  string start = "--";
  string end = "---";

  cout << (string("---") += reverseWordsInString(target)+= string("---")) << endl;
}