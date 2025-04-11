#include <vector>
#include <algorithm>
using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest) {
  std::sort(redShirtSpeeds.begin(),redShirtSpeeds.end());
  std::sort(blueShirtSpeeds.begin(),blueShirtSpeeds.end());
  
  int totalSpeed = 0;
  int left = 0;
  int right = redShirtSpeeds.size() - 1;
  if (fastest) {
    for (left = 0; left <= right;left++) {
      totalSpeed += std::max(redShirtSpeeds[left],blueShirtSpeeds[right-left]);
    }
  } else {
    for (left = 0; left <= right;left++) {
      totalSpeed += std::max(redShirtSpeeds[left],blueShirtSpeeds[left]);
    }
  }
  return totalSpeed;
}
