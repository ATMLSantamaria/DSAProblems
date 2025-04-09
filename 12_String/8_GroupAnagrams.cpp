#include <vector>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string>& words) { // Pass by const&
  
  
  unordered_map<string,vector<string>> anagrams; //unordered_map used because order does not matter

  // Sort a copy of each word and use it as key
  for (const auto &word : words) {               // Pass by reference to avoid copy
    string key = word;                           // Copy is needed here
    std::sort(key.begin(),key.end());
    anagrams[key].push_back(word);               // when key is not in the hash table, C++ initialise the value with default value, in this case an empty vector
  }

  vector<vector<string>> solution;
  solution.reserve(anagrams.size());             // Optimization to avoid reallocations. Important RESERVE, not resize. Reserve guarda memoria para evitar reallocation pero no cambia el size.
  
  // Now iterate and create the solution
  for (auto & [key,value] : anagrams) {          // structured binding, c++17
    solution.push_back(std::move(value));        // Move Semantics are more efficient, we avoid copy the vectors (that could be huge)
  }

  return solution;
}

int main() {

  vector<string> target = {"gato","toga","foo","ofo","ojo","oko","oof","iceman","cinema"};

  auto solution = groupAnagrams(target);

  for (auto &group : solution) {
    cout << "[  ";
    for (auto &word : group){
      cout << word << "  ";
    }
    cout << "]\n";

  }


}
