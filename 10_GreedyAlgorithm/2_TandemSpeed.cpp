#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//2 lines of people to combine in pairs. Speed is define by the fastest. Make combinations to achieve either the maximum posisble sum of 
//velocities either the minimum possible

int tandemBicycle(
  vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest
) {
  int total_speed = 0;
  if (fastest) {
  //Sort array in opposite order. One ascending One descending -> This maximise the total speed
  std::sort(redShirtSpeeds.begin(),redShirtSpeeds.end());
  std::sort(blueShirtSpeeds.rbegin(),blueShirtSpeeds.rend());


  for (int i = 0; i < redShirtSpeeds.size();++i) { 
    total_speed = (redShirtSpeeds[i] > blueShirtSpeeds[i]) ? total_speed + redShirtSpeeds[i] : total_speed + blueShirtSpeeds[i];
  }
  return total_speed;
  
  } else {
  //Sort array in same order. This guarantee that the total speed is minimum
  std::sort(redShirtSpeeds.begin(),redShirtSpeeds.end());
  std::sort(blueShirtSpeeds.begin(),blueShirtSpeeds.end());

  for (int i = 0; i < redShirtSpeeds.size();++i) { 
    total_speed = (redShirtSpeeds[i] > blueShirtSpeeds[i]) ? total_speed + redShirtSpeeds[i] : total_speed + blueShirtSpeeds[i];
  }
  return total_speed;
    
  }

  
  return -1;
}
int main() {
  std::vector<int> line1 = {5,5,1,3,4};
  std::vector<int> line2 = {6,9,2,4,5};
  bool fastest = true;
  std::cout << tandemBicycle(line1,line2,fastest);
}
