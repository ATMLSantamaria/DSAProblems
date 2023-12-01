#include <vector>
#include <climits>
#include <iostream>

using namespace std;

vector<int> selectionSort(vector<int> array) {
  // Write your code here.
  int to_swap = 0;
  int current_min = INT_MAX;
  int index_current_min = 0;
  
  for (int i = 0; i < array.size();++i) {

    current_min = INT_MAX;
    for (int j = i; j < array.size();++j) {
      current_min = (current_min < array[j]) ? current_min : array[j];
      index_current_min = (current_min < array[j]) ? index_current_min : j;
    }
    to_swap = array[i];
    array[i] = array[index_current_min];
    array[index_current_min] = to_swap;
  }
  return array;
}

int main() {

  std::vector<int> target = {1,6,55,4,2,133,4,2,5,55,6,88,4,3,-1000,-100,8765};

  selectionSort(target);

  for (auto & i : target) {
    std::cout << i << ",";
  }
  std::cout << std::endl;

}