#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  std::unordered_set<int> saveElements;
  saveElements.insert(array[0]);
  for (int i = 1; i < array.size();++i) {
    
    int searchedNumber = targetSum - array[i];
    
    if (saveElements.count(searchedNumber)){
      return {searchedNumber,array[i]}; 
    }
    saveElements.insert(array[i]);
    
  }
  return {};
}
