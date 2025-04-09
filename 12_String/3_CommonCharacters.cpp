#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> commonCharacters(vector<string> strings) {
  unordered_map<char,int> myMap;
  unordered_set<char> mySet;
  vector<string> solution;
  
  for (string & str : strings) {
    
    for (char ch : str) {
      if (mySet.count(ch)){
        continue;
      }
      myMap[ch] += 1;
      mySet.insert(ch);
    }
    mySet.clear();
  }
  //C+=17 structured binding
  for (const auto & [key,value] : myMap) {
    if (value == strings.size()) {
      solution.push_back(std::string(1,key)); //convert the char to a single char string. 
    }
  }
  return solution;
}

#include <array>


int firstNonRepeatingCharacterWithArray(std::string str) {
  // Only 26 letters in english alphabet
  std::array<int,26> freqArray{}; // is initialised to 0. The {} are VERY IMPORTANT. Otherwise is not guarantee to be initialised to 0

  // Iterate in the string increasing the frequncy
  for (char ch : str) {
    freqArray[ch - 'a'] += 1;
  }

  // Iterate in the string and find the first position in the array with value 0
  for (size_t i = 0; i < str.size();++i) {
    if (freqArray[str[i] - 'a'] == 1) {
      return i;
    }
  }
  return -1;
}


int main() {
  vector<string> target = {"tayyyyauuuca","arryrtcta","nntwywnnac"};

  vector<string> res = commonCharacters(target);

  for (auto ch : res) {
    cout << ch << "  ";
  }
  cout << endl;
}