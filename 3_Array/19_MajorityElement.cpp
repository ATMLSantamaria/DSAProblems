#include <vector>
#include <cassert>
using namespace std;



int majorityElement(vector<int> array) {
  // Write your code here.
  int appearences = 0;
  int temptative = 0;
  for (int i = 0;i < array.size();++i) {
    appearences = 1;
    temptative = array[i];
    
    while(appearences != 0) {
      i++;
      if (array[i] == temptative) {
        appearences++;
      } else {
        appearences--;
      }
    }
  }     
 
  return temptative;
}


int main() {
  std::vector<int> target = {1,2,3,22,4,22,5,22,6,7,22,22,22,22,22,22,22,22,22,22,22,22,22,22,8,99};
  assert(majorityElement(target) == 22);

}