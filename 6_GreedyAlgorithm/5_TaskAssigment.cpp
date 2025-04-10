#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


// std::transform simply create a vector of pairs {task, index}. Because we need to retrieve the original indexes after sorting this is necessary.
// We dont need to use std::transform. We could have done a typical loop without probem.




vector<vector<int>> taskAssignment(int k, vector<int> tasks) {

  vector<pair<int,int>> helper;
  
  //[index = 0] type of the variable in the capture clause is deduced automatically from its initializer.
  // back inserter is a iterator that expand the container if needed dynamically resizing.
  // Useful for vector, list, deques ...when being used with std::algorithms
  // mutable is needed to modify the captured variable index
  // index++, index is taken and then increased
  std::transform(tasks.begin(),tasks.end(),std::back_inserter(helper),[index = 0] (int task) mutable { 
    return make_pair(task,index++); //index is increased after being used in the make_pair.  A bit difficult to udnerstand but working
  });
  
  std::sort(helper.begin(),helper.end());

  vector<vector<int>> solution;
  solution.reserve(k);

  int left = 0;
  int right = tasks.size() - 1;

  while (left < right) {
    solution.push_back({helper[left].second,helper[right].second});
    left++;
    right--;
  }
  
  return solution;
}
int main() {
  
}