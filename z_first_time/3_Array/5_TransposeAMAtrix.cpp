#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
  // Write your code here.
  
  
  int jj = matrix[0].size(); //numero de columnas
  int ii = matrix.size(); //numero filas

  int i_t = jj; //numero filas nueva matriz
  int j_t = ii; //numero columnas nueva matriz

  vector<vector<int>> result,result2;


  
  for (int i = 0; i < i_t;++i){
    std::vector<int> tmp;
    for (int j = 0; j < j_t;++j) {
       tmp.push_back(matrix[j][i]);
       //result[j][i] = ;
    }
    result2.push_back(tmp);
  }
  
  return result2;
}

void Print2DMatrix(std::vector<std::vector<int>> & res) {
  std::cout << "{\n";

  for (auto & i : res) {
    std::cout << "{ ";
    for (auto &j : i) {
      std::cout << j << " ";
    }
    std::cout << "} \n";
  }
  std::cout << "}\n";
}

int main() {
  std::vector<std::vector<int>> target = {{1,2,3,4,5,6,7},{7,7,7,6,5,4,3}};

  Print2DMatrix(target);
  std::vector<std::vector<int>> res = transposeMatrix(target);
  std::cout << "--------------\n";
  
  Print2DMatrix(res);

}