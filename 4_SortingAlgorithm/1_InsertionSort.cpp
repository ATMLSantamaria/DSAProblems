#include <vector>
#include <iostream>
using namespace std;

void InsertionSort(vector<int> & array) {
  // Write your code here.
  int to_swap = 0;
  int index_of_ecurrently_analysed_element =0;
  for (int i = 0; i < array.size();++i){
    index_of_ecurrently_analysed_element = i;
    for (int j = i; j >= 0; --j) {

      //When move the element to the left, we want to follow the element, so we need to update
      //it index
      if (array[index_of_ecurrently_analysed_element] < array[j]) {
        to_swap = array[j];
        array[j] = array[index_of_ecurrently_analysed_element];
        array[index_of_ecurrently_analysed_element] =to_swap;

        index_of_ecurrently_analysed_element = j;
      }
    }
  }
  //return array;
}

int main() {

  std::vector<int> target = {1,6,55,4,2,133,4,2,5,55,6,88,4,3,-1000,-100,8765};

  InsertionSort(target);

  for (auto & i : target) {
    std::cout << i << ",";
  }
  std::cout << std::endl;

}