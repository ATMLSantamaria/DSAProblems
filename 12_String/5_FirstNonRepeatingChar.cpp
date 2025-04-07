#include <unordered_map>
#include <string>
using namespace std;

int firstNonRepeatingCharacter(string string) {

  unordered_map<char,int> freqMap;

  for (auto i : string) {
    freqMap[i] += 1;
  }

  for (unsigned int i = 0;i < string.size();i++) {
    if (freqMap[string[i]] == 1) {
      return i;
    }
  }
  return -1;
}
