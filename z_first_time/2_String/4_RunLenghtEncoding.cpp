#include <string>
#include <iostream>
#include <cassert>
using namespace std;

string runLengthEncoding(string str) {
  string res;
  int counter = 1;
  for (int i = 0; i < str.size();++i) {
    counter = 1;
    while(str[i + 1] == str[i]) {
      counter++;
      if (counter == 9) {
        res += std::to_string(counter);
        res.push_back(str[i]);
        counter = 0;
      }
      ++i;
    }
    if (counter != 0) {
      res += std::to_string(counter);
      res.push_back(str[i]);
    }
  }
  return res;
}

int main() {
  std::string myTarget = "AAAAABBBBBBBBBBBBBBBBBBBBrrrrreeeeTTTTWWW....";
  assert(std::string("5A9B9B2B5r4e4T3W4.") == runLengthEncoding(myTarget));
}
