#include <unordered_map>
#include <vector>
#include <cassert>

using namespace std;

bool zeroSumSubarray(vector<int> nums) {
  std::unordered_map<int,bool> track_partial_sum;
  int partial_sum = 0;
  
  for (auto & n : nums) {
    partial_sum += n;
    if (n == 0) {
      return true;
    }
    if (partial_sum == 0) {
      return true;
    }

    //If a partial sum with the same vlaue already exist, it means that in the middle there is a 
    //sequence whose sum is =
    if (track_partial_sum.find(partial_sum) != track_partial_sum.end()) {
      return true;
    }   
    track_partial_sum[partial_sum] = true;
  }
  
  return false;
}

int main() {

  std::vector<int> target = {10,100,-90000,-1,2,-1,123,34,33,22};

  assert(zeroSumSubarray(target) == true);
  target = {1,2,3,4,5,6};
  assert(zeroSumSubarray(target) == false);
    target = {1,2,3,0,5,6};
  assert(zeroSumSubarray(target) == true);
  
}