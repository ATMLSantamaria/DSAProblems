#include <unordered_set>
#include <vector>
#include <cassert>

using namespace std;

//Complexity T O(n) S O(n) where n is number of elements in nums
vector<int> MissingNumbersBetter(vector<int> nums) {
  // Write your code here.

  //Which options do we have. 
  // 1 - To sort and iterate nlogn. It seems too easy
  // 2 - Use a hash table to store existing numbers
  // 3 - Count the sum of elements. We know that all elements are member of a array of lengh+2 of unique numners. 
  // Count that hypothetical array. With a substraction we have the sum of both lacking elements. 
  // Then we can separate the first array in 2 using the the middle point between lacking elements. And find both of them
  std::vector<int> res;
   
  //Since each element is unique and we only need to track existance we can use a set

  int total_size = nums.size();

  int sum = 0;

  for (auto & n : nums) {
    sum += n;
  }
  int total_sum = 0;
  for (int i = 1; i <= total_size + 2;++i) {
    total_sum += i;
  }
  //The sum of the "completed list" minus the sum of the incomplete list gives us the sum of the missing numbers
  int sum_of_missing_number = total_sum - sum;

  //sum_of_missing_sumbers = a + b
  // a < sum_of_missing_numbers / 2
  // b > sum_of_missing_numbers / 2



  int average_a_b = sum_of_missing_number / 2;
  int sum_a = 0;
  int sum_b = 0;

  for (auto & n : nums) {
    if (n <= average_a_b) {
      sum_a += n;
    } else {
      sum_b += n;
    }
  }

  
  int total_sum_a = 0;
  int total_sum_b = 0;
  for (int i = 1; i <= average_a_b;++i) {
    total_sum_a += i;
  }
  for (int i = average_a_b + 1; i <= total_size + 2;++i) {
    total_sum_b += i;
  }

  int a = total_sum_a - sum_a;
  int b = total_sum_b - sum_b;

  
  return {a,b};
}


//Complexity T O(n) S O(n) where n is number of elements in nums
vector<int> MissingNumbers(vector<int> nums) {
  // Write your code here.

  //Which options do we have. 
  // 1 - To sort and iterate nlogn. It seems too easy
  // 2 - Use a hash table to store existing numbers
  std::vector<int> res;
  std::unordered_set<int> track; 
  //Since each element is unique and we only need to track existance we can use a set

  int total_size = nums.size();

  for (auto & n : nums) {
    track.insert(n); 
  }

  for (int i = 1; i <= total_size + 2;++i) {
    if (track.find(i) == track.end()) {
      res.push_back(i);
    }
  }
  
  return res;
}

int main() {

  vector<int> target = {1,5,2};
  assert(MissingNumbers(target) == std::vector<int>({3,4}));

}