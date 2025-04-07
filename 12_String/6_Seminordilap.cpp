#include <algorithm>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

string createReverse(string & target) {
  std::string solution(target);
  std::reverse(solution.begin(),solution.end());
  return solution; 
}


vector<vector<string>> semordnilap(vector<string> words) {
  vector<vector<string>> solution;
  unordered_set<string> reversedSet;
  for (auto w : words) {
    string currentReverse = createReverse(w);
    if (reversedSet.count(currentReverse) > 0) {
      solution.push_back({w,currentReverse});
    } else {
      reversedSet.insert(w);
    }
    
  }


  return solution;
}
