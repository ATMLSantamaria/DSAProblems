#include <vector>
#include <algorithm>
#include <cassert>


using namespace std;

//Each vector represent the height of one line of students. Thez come in t shits of 2 colors that define their line
// It is possible to organise them in 2 lines so behind they are always taller. 
//all students with same colour should be in same line

//Complexity T O(nLogn) S O(1)
bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  // Write your code here.
  std::sort(redShirtHeights.begin(),redShirtHeights.end());
  std::sort(blueShirtHeights.begin(),blueShirtHeights.end());

  bool blue_behind = true;

  blue_behind = (redShirtHeights.back() < blueShirtHeights.back()) ? true : false;

  if (blue_behind) {
    for (int i = 0; i < redShirtHeights.size();++i) {  
      if (blueShirtHeights[i] <= redShirtHeights[i]) {
        return false;
      }
    }
  } else {
    for (int i = 0; i < redShirtHeights.size();++i) {
      if (redShirtHeights[i] <= blueShirtHeights[i]) {
        return false;
      }
    }
  }
  
  return true;
}

int main() {
  std::vector<int> line1 = {5,8,1,3,4};
  std::vector<int> line2 = {6,9,2,4,5};

  assert(classPhotos(line1,line2));

}
