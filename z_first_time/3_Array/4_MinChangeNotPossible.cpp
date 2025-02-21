#include <vector>
#include <cassert>
#include <algorithm>


int nonConstructibleChange(std::vector<int> & coins) {

  // 1st Sort the array
  std::sort(coins.begin(),coins.end());

  // 2nd. Store max change current
  int max_change_current = 0;

  // 3nd iterate through it
  for (auto &i : coins) {
    if (i > max_change_current + 1) { // In that case max_change + 1 is impossible to create so is the minimum nonConstructibleChange in the array
      return max_change_current + 1;
    } else {   //We can genrate previous change plus the new coin
      max_change_current += i;
    }
  }

  //4 If the loop didnt return we have a max change we can change. 1 unit more than the max change it is the min change we can not cahnge
  return max_change_current + 1;

}

int main () {

  std::vector<int> target1 = {1,1,2,4,10}; //min not possible change = 9
  std::vector<int> target2 = {1,1,2,4,9}; // min not possible change = 18
  std::vector<int> target3 = {1}; // min not possible change = 182

  assert(nonConstructibleChange(target1) == 9);

  assert(nonConstructibleChange(target2) == 18);

  assert(nonConstructibleChange(target3) == 2);




}