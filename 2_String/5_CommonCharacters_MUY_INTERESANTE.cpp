#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <utility>
#include <cassert>
using namespace std;


//Complexity T O(n*m) S O(m)   where n is number of string in strings and m is the number of char in the longest string
vector<string> commonCharacters(vector<string> strings) {
  // Write your code here.
  std::unordered_map<char,int> tracking; 
  std::vector<string> res;

  for(auto & s : strings) {
    
    std::unordered_set<char> unique_char;
    //For each element use the set to get unique char in that string
    for (auto & c : s) {
      unique_char.insert(c);
    }

    //Then iterate in the set and increase the appearences in the map
    for (std::unordered_set<char>::iterator it = unique_char.begin();it != unique_char.end();it++) {
      tracking[*it]++;
    } 
  }

  //After finish it, the elements that appear n times (with n = length(strings)) are added to
  //res vector
  std::for_each(tracking.begin(),tracking.end(),[&res,strings](const std::pair<char, int>& pair){
    if (pair.second == strings.size()) {
      res.push_back(std::string(1,pair.first));
    }
    
  });
  

  return res;
}


int main() {

  std::vector<std::string> target = {"aabcp","bzxssssp","cbp"};


  assert(commonCharacters(target) == std::vector<std::string>({"b","p"}));





}


