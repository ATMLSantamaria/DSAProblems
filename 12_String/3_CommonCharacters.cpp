#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

vector<string> commonCharacters(vector<string> strings) {
  unordered_map<char,int> myMap;
  
  vector<string> solution;
  
  for (string & str : strings) {
    unordered_set<char> mySet;
    for (char ch : str) {
      if (mySet.count(ch)){
        continue;
      }
      myMap[ch] += 1;
      mySet.insert(ch);
    }
  }
  //C+=17 structured binding
  for (const auto & [key,value] : myMap) {
    if (value == strings.size()) {
      solution.push_back(std::string(1,key)); //convert the char to a single char string
    }
  }

  
  return solution;
}
