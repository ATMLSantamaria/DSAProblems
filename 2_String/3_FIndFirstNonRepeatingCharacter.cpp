#include <unordered_map>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

//Complexity T O(N) S O(1) where N is the number of elements in the input array
//Why O (1). Well in reality O(26). The string only have lowercase english letters
//So maximum size is 26. After it simply the key increases its value
int firstNonRepeatingCharacter(string string) {

  std::unordered_map<char,int> check;

  int index = 0;
  for (auto i : string){
    if (check.find(i) != check.end()){
      check[i] = check[i] + 1;
    } else {
      check[i]=1;
    } 
  }
  
  for (auto & i : string) {
    if (check[i] == 1) {
      return index;
    }
    index++;
    
  }
  return -1;
}


int main () {
  std::string target = "aaaaaarrrrrrrrrffffffffffgggggggggddddddeeeeeeeeeelllllllllllkkkmkkkkkkjjjjjjjjghsdfjsjlkdkfgjdkfbxjdkfbjdkbjdfk";

  int index = firstNonRepeatingCharacter(target);

  assert(firstNonRepeatingCharacter(target) == 64);
  assert(target[firstNonRepeatingCharacter(target)] == 'm');


}