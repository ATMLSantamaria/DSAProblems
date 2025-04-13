#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> solution;
       unordered_map<string,vector<string>> anagrams;

       for (auto & word : strs) {
            string key = word;
            std::sort(key.begin(),key.end());
            anagrams[key].push_back(word);
       }

       // I have now all anagrams in the map, ordered by keys
       for (auto & [key,value] : anagrams) {
        solution.push_back(std::move(value));
       }
       return solution;
        
    }
};


