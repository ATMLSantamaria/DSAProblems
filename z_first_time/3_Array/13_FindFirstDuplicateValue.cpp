#include <vector>
#include <unordered_map>
#include <cmath>
#include <cassert>

using namespace std;

//Solution with HASH TABLE -> C
//Complexity T O(N) S O(N)
int firstDuplicateValueWithHashTable(vector<int> array) {
  std::unordered_map<int,int> tracking;
  for (auto & i : array) {

    tracking[i]++; //Wich ints this should work, they will be initialise to 0. Otherwise we should use tracking.find() == nullptr for insertion
    if (tracking[i] == 2) {
      return i;
    }
  }
  return -1;
}

//Optimal solution, it does not need a Hash Table
int FirstDuplicateValueBetter(vector<int> array) {

  //Clue: Integers from 1 to n so positive integers
  //Clue 2: n is the length of the array. 

  //We can map the integers to a position in the array. pos = value -1
  //Then mark that position making it negative.
  //Later if we found a negative position, we have the result

  for (auto & i: array) {
    int index = abs(i) - 1;
    if (array[index] < 0) {
      return abs(i);
    }
    array[index] *= -1; 
    //Here we mark this position,
    //so if later we visit it again we know is the second appearence of a number
  }
  return -1;
}

int main() {
  std::vector<int> target = {1,5,4,2,9,8,2};
  assert(firstDuplicateValueWithHashTable(target) == 2);
  assert(FirstDuplicateValueBetter(target) == 2);
}