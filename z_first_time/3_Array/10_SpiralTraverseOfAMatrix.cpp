#include <vector>
#include <iostream>
#include <cassert>

using namespace std;


void MoveRightOnLineFromXUntilY(std::vector<std::vector<int>> & array,int line,int X,int Y,std::vector<int> & res) {
  size_t s_max = array[0].size() * array.size();
  int i = X;
  while(i <= Y  && res.size() <= s_max  ) {
    res.push_back(array[line][i]);
    i++;
  }
}

void MoveDownOnColumFromXUntilZ(std::vector<std::vector<int>> & array,int column,int X,int Z,std::vector<int> & res) {
  size_t s_max = array[0].size() * array.size();
  int i = X;
  while (i <= Z && res.size() <= s_max  ) {
    res.push_back(array[i][column]);
    i++;
  }
}

void MoveLeftOnLineFromXUntilY(std::vector<std::vector<int>> & array, int line,int X,int Y,std::vector<int> & res) {
  size_t s_max = array[0].size() * array.size();
  int i = X;
  while (i >= Y   && res.size() <= s_max  ) {
    res.push_back(array[line][i]);
    i--;
  }
}

void MoveUpOnColumsFromUXntilZ(std::vector<std::vector<int>> & array, int column,int X,int Z,std::vector<int> & res) {
  size_t s_max = array[0].size() * array.size();
  int i = X;
  while (i >= Z    && res.size() <= s_max  ) {
    res.push_back(array[i][column]);
    i--;    
  }
}

void PrintRes(std::vector<int> & res) {
  for (auto & i : res) {
    std::cout << i << ",";
  }
  std::cout << std::endl;
}


vector<int> spiralTraverse(vector<vector<int>> & matrix) {
  vector<int> res;
  

  int left = 0;
  int right = matrix[0].size() - 1;

  int top = 0;
  int bottom = matrix.size() - 1;

  while(left <= right && top <= bottom) {
    
    if (left != right) {
      MoveRightOnLineFromXUntilY(matrix,top,left,right,res);
      top++;
    }

    if (top !=  bottom) {
      MoveDownOnColumFromXUntilZ(matrix,right,top,bottom,res);
      right--;
    }
 

    if (left != right) {
      MoveLeftOnLineFromXUntilY(matrix,bottom,right,left,res);
      bottom--;
    }


    MoveUpOnColumsFromUXntilZ(matrix,left,bottom,top,res);
    left++;
  }

  return res;
}

int main() {
  std::vector<std::vector<int>> matrix = {{1, 2, 3, 4,100},
                                        {12, 13, 14, 5,101},
                                        {11, 16, 15, 6,102},
                                        {10, 9, 8, 7,103}
                                        };
  std::vector<int> res = spiralTraverse(matrix);
  assert(res == std::vector<int>({1,2,3,4,100,101,102,103,7,8,9,10,11,12,13,14,5,6,15,16}));
  //PrintRes(res);
  std::vector<std::vector<int>> matrix2 = {{1,2,4,5},
                                           {10,11,12,5},
                                           {9,8,7,6}};

  std::vector<int> res2 = spiralTraverse(matrix2);  
  //PrintRes(res2);                              
  



  // int left = 0;
  // int right = matrix[0].size() - 1;

  // int top = 0;
  // int bottom = matrix.size() - 1;

  // while(left <= right && top <= bottom) {
    
  //   // MoveRightOnLineFromXUntilY(matrix,0,left,right,res);
  //   MoveRightOnLineFromXUntilY(matrix,top,left,right,res);
  //   PrintRes(res);
  //   top++;

  //   // MoveDownOnColumFromXUntilZ(matrix,3,top,bottom,res);
  //   MoveDownOnColumFromXUntilZ(matrix,right,top,bottom,res);
  //   PrintRes(res);
  //   right--;

  //   // MoveLeftOnLineFromXUntilY(matrix,3,right,left,res);
  //   MoveLeftOnLineFromXUntilY(matrix,bottom,right,left,res);
  //   PrintRes(res);
  //   bottom--;

  //   // MoveUpOnColumsFromUXntilZ(matrix,0,bottom,top,res);
  //   MoveUpOnColumsFromUXntilZ(matrix,left,bottom,top,res);
  //   PrintRes(res);
  //   left++;

  // }


  
}
