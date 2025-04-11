#include <vector>
#include <algorithm>
using namespace std;
// 1 2 3 4 5
// 2 3 4 5 6
bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  std::sort(redShirtHeights.begin(),redShirtHeights.end());
  std::sort(blueShirtHeights.begin(),blueShirtHeights.end());

  if (blueShirtHeights[0] == redShirtHeights[0]) {
    return false;
  } else if (blueShirtHeights[0] > redShirtHeights[0]) {
    for (int i = 0; i < redShirtHeights.size();++i) {
      if (redShirtHeights[i] >= blueShirtHeights[i]) {
        return false;
      }
    }
  } else {
    for (int i = 0; i < redShirtHeights.size();++i) {
      if (blueShirtHeights[i] >= redShirtHeights[i]) {
        return false;
      }
    }
  }
  
  return true;
}
