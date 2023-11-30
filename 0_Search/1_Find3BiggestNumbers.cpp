#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {

  std::vector<int> res = {INT_MIN,INT_MIN,INT_MIN};

  for (int i = 0; i < array.size();++i) {
    if (array[i] >= res[2]) {
      res[0] = res[1] ;
      res[1] = res[2] ;
      res[2] = array[i];
      continue;
    } else if (array[i] >= res[1] ) {
      res[0] = res[1];
      res[1] = array[i];
      continue;
    } else if (array[i] >= res[0]) {
      res[0] = array[i];
      continue;
    }
  }
  return res;
}


int main() {

  std::vector<int> myVector = {8,99,1,100,101,3,4,5,6,3};
  std::vector<int> res = findThreeLargestNumbers(myVector);

  for (auto & i : res) {
    std::cout << i << ",";
  }
  std::cout << std::endl;

}