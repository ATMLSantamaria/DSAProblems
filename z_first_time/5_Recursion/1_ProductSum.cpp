#include <any>
#include <vector>
#include <cassert>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)
int productSum(vector<any> array,int depth = 1) {
  depth++;
  int sum = 0;
  for (auto & el : array) {
    if (el.type() == typeid(vector<any>)) {
      sum = sum + depth * productSum(std::any_cast<std::vector<any>>(el),depth);
    } else {
      sum = sum + std::any_cast<int>(el);
    }
  }
  return sum;
}


int main() {
  std::vector<std::any> myVector = {5, 2, std::vector<std::any>{7, -1}, 3, std::vector<std::any>{6, std::vector<std::any>{-13, 8}, 4}};
  assert(productSum(myVector) == 12);
}