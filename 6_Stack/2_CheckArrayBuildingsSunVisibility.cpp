//Each number in the array mean the number of floors of a building. The Sun is on the right or on the left (of the array)
//Give back the array with the indexes of buildings that are able to see the sun at least in one floor

#include <stack>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

vector<int> SunsetViewsOldStyleIteration(vector<int> buildings, string direction) {

  std::stack<int> trackTallest;
  std::vector<int> res;
  if (buildings.empty()) {
    return {};
  }

  //For East direction the stack is better. For west direccion we can push directly to the res vector
  if (direction == "EAST") {

    trackTallest.push(buildings.size() - 1);

    for (int i = buildings.size() - 2;i >= 0;--i) {
      if (buildings[i] > buildings[trackTallest.top()]) {
        trackTallest.push(i);
      }
    }

    //trackTallest contains all indexes that see the sun. But they need to be rpesented in opposite order
    res.reserve(trackTallest.size());
    while(!trackTallest.empty()) {
      res.push_back(trackTallest.top());
      trackTallest.pop();
    }

    return res;
  } else {
    res.push_back(0);
    for (int i = 0; i < buildings.size();++i) {
      if (buildings[i] > buildings[res.back()]) {
        res.push_back(i);
      }
    }
    
    return res;
  }

  return {};
}

#include <stack>
using namespace std;

//Reverse iterators are a pretty fancy feature
vector<int> SunsetViewsUsingReverseIterators(vector<int> buildings, string direction) {

  std::stack<int> trackTallest;
  std::vector<int> res;
  if (buildings.empty()) {
    return {};
  }

  //For East direction the stack is better. For west direccion we can push directly to the res vector
  if (direction == "EAST") {
    
    int index = buildings.size() - 1;
    trackTallest.push(index);

    //Indeed for this example a normal loop is better.
    //I just wanted to test the reverse iterator
    for (auto it = buildings.rbegin();it != buildings.rend();it++) {
      
      if (*it > buildings[trackTallest.top()]) {
        trackTallest.push(index);
      }
      --index;
    }

    std::vector<int> res;
    res.reserve(trackTallest.size());

    while(!trackTallest.empty()) {
      res.push_back(trackTallest.top());
      trackTallest.pop();
    }
    return res;
  } else {
    
    int index = 0;
    //TO avoid reallocations that slow down, although if memory of system is limited I would comment this out
    res.reserve(buildings.size()); 
    res.push_back(0);
    
    for (auto it = buildings.begin();it != buildings.end();it++) {
      if (*it > buildings[res.back()]) {
        res.push_back(index);
      }
      index++;
    }
    return res;
  }
  
  
  
  return {};
}

int main() {
  std::vector<int> target1 = {1,2,5,1,8,7}; //indexes 0,1,2,4 can see the sun if sun come from west (left). And only index 4 and 5 can see the sun if come from east

  assert(SunsetViewsOldStyleIteration(target1,"WEST") == std::vector({0,1,2,4}));
  assert(SunsetViewsOldStyleIteration(target1,"EAST") == std::vector({4,5}));

  assert(SunsetViewsOldStyleIteration(target1,"EAST") == SunsetViewsUsingReverseIterators(target1,"EAST"));



}