// Return true if with one edit to one char in only one of the strings you can make them equal. The edit can be replacing a char by a different one or inserting a char

#include <cmath>
#include <string>
using namespace std;

bool oneEdit(string stringOne, string stringTwo) {
  if (stringOne == stringTwo) {
    return true;
  }

  int sizeDiff = abs(static_cast<int>(stringOne.size()) - static_cast<int>(stringTwo.size()));
  
  if (sizeDiff > 1) {
    return false;
  }
  
  // Move until reaching a index that differ.
  int i = 0;
  while (stringOne[i] == stringTwo[i]) {
    i++;
  }

  // We need to check if that is the only different char in all the strings
  // 2 possibilities. Either one is shorter and we insert. Either both equal in size and we replace 1 element. Otherwise we will return false

  // In all cases we reach the element that differ, and compare both strings after that point.

  if (sizeDiff == 0) {
    
    return stringOne.substr(i+1) == stringTwo.substr(i+1);

  } else if (stringOne.size() < stringTwo.size()) {

    return stringOne.substr(i) == stringTwo.substr(i+1); 

  } else {

    return stringOne.substr(i+1) == stringTwo.substr(i);
  }

  return false;
}
