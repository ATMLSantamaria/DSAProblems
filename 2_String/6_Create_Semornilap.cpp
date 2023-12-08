#include <string>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

std::string generateInverseWord(std::string & target) {
  std::string res(target.size(),' ');
  for (int i = 0;i < target.size();++i) {
    res[target.size() - 1 - i] = target[i];
  }
  return res;
}


vector<vector<string>> semordnilap(vector<string> words) {
  vector<vector<string>> res;
  unordered_set<std::string> trackingInverse;
  for (auto & s : words) {
    if (trackingInverse.find(generateInverseWord(s)) == trackingInverse.end()) {
      trackingInverse.insert(s);
    } else {
      res.push_back({s,generateInverseWord(s)});
    }
  }
  
  return res;
}

int main() {

  std::vector<std::string> target = {"hola","adios","aloh"};

  vector<vector<string>> res = semordnilap(target);
	
  for (auto &i : res) {
    for (auto &j : i) {
      std::cout << j <<std::endl;
    }
  }


}
