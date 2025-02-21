#include <vector>
#include <iostream>
using namespace std;

//Brute Force Sort. Take T O(n^2) even in best case
void InsertionSort(vector<int> & array) {
  // Write your code here.
  int to_swap = 0;
  int index = 0;

  for (int i = 0; i < array.size();++i){
    index = i;
    for (int j = i; j >= 0; --j) {
      //When move the element to the left, we want to follow the element, so we need to update
      //it index
      if (array[index] < array[j]) {
        to_swap = array[j];
        array[j] = array[index];
        array[index] =to_swap;

        index = j;
      }
    }
  }
  //return array;
}

//This is real insertion sort. The other is a bastard version that perform extra calculations, since it does not take into consideration that at each spep
// the list to the left is sorted.

// Complexity Best case T O(n) Average and Worst O(n^2). S O(1)
void InsertionSortReal(vector<int> & array) {
  // Write your code here.
  int to_swap = 0;
  int index = 0;
  
  for (int i = 1; i < array.size();++i){
    index = i;

      while(array[index] < array[index - 1] && index != 0) {

        to_swap = array[index];

        array[index] = array[index - 1];

        array[index -1] =to_swap;

        index--;
      }

  }
  //return array;
}

int main() {

  std::vector<int> target = {1,6,55,4,2,133,4,2,5,55,6,88,4,3,-1000,-100,8765};

  InsertionSortReal(target);

  for (auto & i : target) {
    std::cout << i << ",";
  }
  std::cout << std::endl;

}