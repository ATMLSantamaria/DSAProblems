
#include <vector>
#include <iostream>

using namespace std;


//This function will merge overlaping intervals when thez are neighbours
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  // Write your code here.
  int first_first = 0;
  int first_second = 0;
  int second_second = 0;
  int second_first = 0;
  std::vector<std::vector<int>> res;
  for (int i = 0; i < intervals.size();++i) {
    if (i == intervals.size() -1 ) {
      res.push_back(intervals[i]);
      return res;
    }
    
    first_first = intervals[i][0];
    first_second = intervals[i][1];
    
    second_first = intervals[i + 1][0];
    second_second = intervals[i + 1][1];
    
    while( second_first <= first_second) {
      ++i;
      first_second = intervals[i][1];
      if (i == intervals.size() - 1) {
        break;
      }
      second_first = intervals[i + 1][0];
    }
    res.push_back(std::vector<int>({first_first,first_second}));
    
  }
  return res;
}

void PrintRes(std::vector<std::vector<int>> & res) {
  for (auto & i : res) {
    std::cout << "{";
    for (auto & j : i) {
      std::cout << j << ",";
    }
    std::cout << "},\n";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<std::vector<int>> target = {{1, 2},
                                          {3, 5},
                                          {4, 7},
                                          {6, 8},
                                          {9, 10}
                                        };
std::vector<std::vector<int>> res = mergeOverlappingIntervals(target);

PrintRes(res);

}