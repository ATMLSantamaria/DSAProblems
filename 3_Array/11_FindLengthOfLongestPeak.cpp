#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

int longestPeak(vector<int> & array) {
  //Anything smaller than 3 cant have a peak
  if (array.size() < 3) {
    return 0;
  }
  //General case
  int max_length = 0;
  int current_length = 0;
  int p_minus_1 = 0;
  int p_plus_1 = 0;
  int peak = 0;
  
  for (int p = 1; p < array.size() - 1;++p) {
    p_minus_1 = array[p - 1];
    p_plus_1 = array[p + 1];
    peak = array[p];

    current_length = 0;
    //Possible peak
    if (peak > p_minus_1) {

      //In the moment you analyse you are already in the peak, so minimum current_lenght would be 2
      current_length = 2;
      
      while(array[p + 1] > array[p] && p < array.size()) {
        p++;
        current_length++;
      }
      //In case p reach the end of the array  going up it means that this last possible peak is not a peak
      if (p == array.size()-1) {
        return max_length;
      }
      //Si p+1 = peak tampoco es un peak
      if (array[p + 1] == array[p]) {
        continue;
      }
      // Only in this case this is a peak, so we compute length in going down
      while (array[p + 1] < array[p] && p < array.size() - 1) {
        p++;
        current_length++;
        max_length = (current_length > max_length) ? current_length : max_length;
      }
      
    } 
  }
  
  return max_length;
}

int main() {

  std::vector<int> myVector = {1, 2, 3, 4, 5, 1};
  assert(longestPeak(myVector) == 6);

  std::vector<int> myVector2 = {1, 1, 3, 2, 1};
  assert(longestPeak(myVector2) == 4);
  
  std::vector<int> myVector3 = {5, 4, 3, 2, 1, 2, 10, 12};
  assert(longestPeak(myVector3) == 0);
}