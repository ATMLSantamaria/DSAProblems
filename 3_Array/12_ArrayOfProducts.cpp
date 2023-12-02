#include <vector>
#include <iostream>

using namespace std;

//Complexity T O(N) S O(N) where N is the length of the array
//Time is O(N) due to the need to iterate through the elements. We do it twice but that is constant so O(N)
//Space is O(N) due to the necessity of a data structure to store intermediate results of the first iteration
vector<int> arrayOfProducts(vector<int> & array) {
  // Write your code here.
  std::vector<int> res(array.size());
  //First time we multiply all elements before i
  int current_product = 1;
  for (int i = 0; i < array.size();++i) {
    res[i] = current_product;
    current_product *= array[i];
  }
  //Second time we multiply all elements after i
  current_product = 1;
  for (int i = array.size()-1;i >= 0;--i) {
    res[i] = res[i]*current_product;
    current_product = array[i] * current_product;
  }
  
  return res;
}

void PrintRes(std::vector<int> & res) {
  for (auto & i : res) {
    std::cout << i << ",";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> target = {5,1,4,2};

  std::vector<int> res = arrayOfProducts(target);

  PrintRes(res);
}