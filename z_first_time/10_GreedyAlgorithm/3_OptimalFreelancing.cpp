#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

//Complexity T O(nlogn) S O(1) where n is the number of element in the jobs array
int optimalFreelancing(vector<unordered_map<string, int>> jobs) {
  int res = 0;

  std::sort(jobs.begin(),jobs.end(),[](const auto & it1,const auto &it2){
    return it2.at("payment") < it1.at("payment");
  });

  //Schedule
  std::vector<int> week(7,0);

  for (auto & job : jobs) {
    int payment = job.at("payment");
    int deadline = job.at("deadline");
    for (int day = 7; day >= 1;--day) {
      if (payment > week[day - 1] && day <= deadline) {
        week[day - 1] = payment;
        break;
      }
    }
  }

  for (auto & payment : week) {
    res += payment;
  }

  return res;
}

int main(){
  std::vector<std::unordered_map<std::string, int>> target = {
    {{"deadline", 2}, {"payment", 1}},
    {{"deadline", 1}, {"payment", 4}},
    {{"deadline", 3}, {"payment", 2}},
    {{"deadline", 1}, {"payment", 3}},
    {{"deadline", 4}, {"payment", 3}},
    {{"deadline", 4}, {"payment", 2}},
    {{"deadline", 4}, {"payment", 1}},
    {{"deadline", 5}, {"payment", 4}},
    {{"deadline", 8}, {"payment", 1}}
  };

  int res = optimalFreelancing(target);

  assert(res == 16);
}