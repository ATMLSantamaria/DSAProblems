using namespace std;
#include <vector>
#include <algorithm>
#include <iostream>

// Majority element is such elemement that appears more than n/2 itmes in the array.

// Several ways of doing this problem

// First. Brute Force. We sort the array. The majority element (if existance is guaranteed) will always be in the middle

int majorityElementBrute(vector<int> array) {
  std::sort(array.begin(),array.end());
  int middle = array.size() / 2; //integer division

  return array[middle];

}

// Second brute force approach. use a map to track the appearence of elements
int majorityElementBrute2(vector<int> array) {
  std::unordered_map<int,int> tracking;

  int currentMajority = 0;
  for (auto num : array) {
    if (tracking.count(num) == 0) {
      tracking[num]=1;
    } else {
      tracking[num] += 1;
    }
    if (tracking[num] > tracking[currentMajority]) {
      currentMajority = num;
    }
  }
  return currentMajority;
}


// Clever approach. O(n) time and O(1) space. This works only becuase it is guaranteed that there is a majority element
int majorityElementClever(vector<int> array) {
  int counter = 1;
  int majorityElement = array[0];
  for (uint32_t i = 1; i < array.size();++i) {
    if (majorityElement != array[i]){
      counter--;
    } else {
      counter++;
    }
    if (counter == 0) {
      majorityElement = array[i];
      counter++;
    }
  }
  return majorityElement;


}

int main() {
  std::vector<int> test = {2,3,2,3,3,3,1,2,3,5,6,3};
  std::cout << majorityElementBrute(test) << std::endl;
  std::cout << majorityElementBrute2(test) << std::endl;
  std::cout << majorityElementClever(test) << std::endl;





}