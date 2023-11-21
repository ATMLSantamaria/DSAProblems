#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
  int smallest = 0;
  int largest = array.size()-1;
  
  std::vector<int> result(array.size());
  
  int index = array.size()-1;
  
  while(largest >= smallest ) {

    if (abs(array[largest]) > abs(array[smallest])) {
      result[index] = pow(array[largest],2);
      largest--;
    } else {
      result[index] = pow(array[smallest],2);
      smallest++;
    }
    --index;
    
  }
  return result;
}


int main () {

  std::vector<int> target = {-5,-4,-2,0,1,2,2,2,2,3,4,8,10};
  std::vector<int> target2 = {-5,-4,-2,0,1,2,3,4,10};
  std::vector<int> result = sortedSquaredArray(target);
  std::vector<int> result2 = sortedSquaredArray(target2);


  for (auto  &i : result) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  
  for (auto  &i : result2) {
    std::cout << i << " ";
  }
   
  std::cout << std::endl;

}