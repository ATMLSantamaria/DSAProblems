#include <vector>
#include <cassert>
using namespace std;

int bestSeat(vector<int> seats) {
  // Write your code here.
  int max_space = 0;
  int index_max_space = 0;

  int current_space = 0;
  int current_index = -1;

  int start_index = -1, end_index = -1;
  int current_start_index = -1, current_end_index = -1;
  

  for (int i = 0; i < seats.size();++i) {

    current_space = 0;
    current_index = -1;
    
    if (seats[i] == 0) {
      current_start_index = i;
    }
    while (seats[i] == 0) {
      current_space++;
      i++;
    }
    current_end_index = i;
    current_index = i - current_space;

    if (current_space > max_space) {
      max_space = current_space;
      index_max_space = current_index;

      start_index = current_start_index;

      end_index = current_end_index;
      
    }
    
  }
  if (start_index == -1) {
    return -1;
  }

  if ((end_index - start_index) % 2 == 0) {
    return start_index + (max_space / 2) - 1;
  } else {
    return start_index + max_space / 2;
  }
  
  return index_max_space + (current_space / 2);
}

int main() {
  std::vector<int> target = {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1};
  assert(bestSeat(target) == 4);
  
  std::vector<int> target2 = {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1};
  assert(bestSeat(target2) == 8);



}