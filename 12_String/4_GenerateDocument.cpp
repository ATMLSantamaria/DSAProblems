#include <unordered_map>
using namespace std;

bool generateDocument(string characters, string document) {
  // Create a map with the frecuqncies of the characters
  unordered_map<char,int> freqMap;
  for (auto ch : characters) {
    freqMap[ch] += 1; //if ch not in map it will add, otherwise it increase the counters
  }

  for (auto ch : document) {
    if (freqMap[ch]==0) { // if key is not there freqMap[key] is initialised to default value so to 0
      return false;
    }
    freqMap[ch] -= 1;
  }

  return true;
}
