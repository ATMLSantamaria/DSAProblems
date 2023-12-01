#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

//Complexitx T  O(nlog(n) + mlog(m)) S O(1) 
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {

  // std::vector<int> res = {arrayOne[0],arrayTwo[0]};

  std::sort(arrayOne.begin(),arrayOne.end());
  std::sort(arrayTwo.begin(),arrayTwo.end());

  int it_one = 0;
  int it_two = 0;
  
  int min_dif = INT_MAX;
  int current_dif = INT_MAX;

  std::vector<int> res(2);


  
  //Sorted arrys -> they increase when iterators increase
  //If we each time increase the iterator of the smallest of the elements, we logically bring closer the element 
  while (it_one < arrayOne.size() && it_two < arrayTwo.size()) {

    int firstNum = arrayOne[it_one];
    int secondNum = arrayTwo[it_two];
    
    if(firstNum < secondNum) {
      current_dif = secondNum - firstNum;
      it_one++;   
      
    } else if (secondNum < firstNum) {
      current_dif = firstNum - secondNum;
      it_two++;
      
    } else {
      //If both are equal difference is minimum so we return
      return std::vector<int>{firstNum,secondNum};
      
    }

    if (min_dif > current_dif ) {
      min_dif = current_dif;
      res = {firstNum,secondNum};
    }
  }

  return res;
}


int main() {
  std::vector<int> array_one =  {-1, 5, 10, 20, 28, 3};
  std::vector<int> array_two =  {26, 134, 135, 15, 17};

  std::vector<int> res = smallestDifference(array_one,array_two);

  std::cout << "{" << res[0] << "," << res[1] << "}\n";

}

