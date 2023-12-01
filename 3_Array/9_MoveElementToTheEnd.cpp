#include <vector>
#include <iostream>

using namespace std;

vector<int> moveElementToEnd(vector<int> & array, int toMove) {

  int end_counter = array.size() - 1;
  int to_swap = 0;
  
  for (int i = 0; i < array.size();++i) {

    if (array[i] == toMove) {
      to_swap = array[i];
      while(array[i] == array[end_counter] ) {
        end_counter--;
      }
      if  (end_counter <= i) {
        break;
      }
      array[i] = array[end_counter];
      array[end_counter] = to_swap;
      end_counter--;
    }   
    if (end_counter <= i) {
      break;
    }
  
    
  }
  return array;
}

int main() {
  std::vector<int> myTarget = {2, 1, 2, 2, 2, 3, 4, 2};

  moveElementToEnd(myTarget,2);

  for (auto & i : myTarget) {
    std::cout << i << ",";
  }
  std::cout << std::endl;
}