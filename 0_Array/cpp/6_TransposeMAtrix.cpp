#include <vector>
using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
  int newNColums = matrix.size();
  int newNRows = matrix[0].size();

  // With this I create new MAtrix with the correct size
  vector<vector<int>> solution(newNRows,vector<int>(newNColums,0));

  for (int i = 0; i < solution.size();++i) {
    for (int j = 0; j < solution[0].size();++j) {
      solution[i][j] = matrix[j][i];
    }
  }

  return solution;
}
