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
      solution.push_back(std::string(1,key)); //convert the char to a single char string. Use std::move for more efficiency. In this case, since char is a primitive, this is 
    }
  }
  return solution;
}

int main() {
  vector<string> target = {"tayyyyauuuca","arryrtcta","nntwywnnac"};

  vector<string> res = commonCharacters(target);

  for (auto ch : res) {
    cout << ch << "  ";
  }
  cout << endl;
}