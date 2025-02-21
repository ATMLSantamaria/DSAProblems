#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

bool IsMonotonic(vector<int> array) {

  //in the moment a element is not following the tendency, is monotonic
  if (array.empty() || array.size() == 1) {
    return true;
  }

  std::vector<int>::iterator it = ++array.begin(); //it start in second element

  for (;it != std::prev(array.end());) { //it end in the "penultimo" element. 2 different wazs of doing this

    std::vector<int>::iterator it_post_it = std::next(it);
    std::vector<int>::iterator it_before_it = std::prev(it); //when it is first element return it, later return prev

    //Skip equal values since they dont provide info
    while(*it_post_it == *it && std::next(it_post_it) != array.end()) {
      it_post_it = std::next(it_post_it);
    }
    std::cout << "hello\n";

    //Now compare
    
    if (*it_post_it > *it && *it_before_it > *it ) { //it is local minimum
      return false;
    } else if (*it_post_it < *it && *it_before_it < *it ) {  //it is local maximum
      return false;
    }

    it = it_post_it;
    
  }
  
  return true;
}

int main() {
  std::vector<int> target = {-1, -5, -10, -1100, -1100, -1101, -1102, -9001}; //true
  std::vector<int> target2 = {-1, -1, -1, -1, -1, -1, -1, -1}; 

  bool res = IsMonotonic(target2);

  std::string result = res ? "true" : "false";

  std::cout << result << std::endl;

}