#include <string>

using namespace std;

void moveChar(char & target,int k);
string caesarCypherEncryptor(string str, int key) {

  for (auto & i: str) {
    moveChar(i,key);
  }
  return str;
}

// Move each char k position in the alphabet means simply to add that to the char

void moveChar(char & target,int k) {
  int alphabetSize = 'z' - 'a'+ 1;
  k = k % alphabetSize;

  if (target + k > 'z'){
    target = target + k - alphabetSize;
  } else {
    target = target + k;
  }
}