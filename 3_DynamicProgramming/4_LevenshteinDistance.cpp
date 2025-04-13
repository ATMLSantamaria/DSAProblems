#include <vector>
#include <string>
#include <iostream>
using namespace std;

// str1 yabd
// str2 abc
//         ""  y   a   b   d
//   ""    0   1   2   3   4
//   a     1
//   b     2
//   c     3
// La parte de arriba es la inizializacion que hay que ahcer siempre antes de entrar en el algoritmo

int levenshteinDistance(string str1, string str2) {
  // Write your code here.
  // Usamos es constructor de vector (size,defaultValue)
  vector<vector<int>> editMatrix(str2.size()+1,vector<int>(str1.size()+1,0));

  // Initialize first row. We move the column
  for (int c = 0;c <= str1.size();++c) {
    editMatrix[0][c] = c;
  }

  // Initialize first colum. We move the row
  for (int r = 0; r <= str2.size();++r) {
    editMatrix[r][0] = r;
  }

  // Now we can proceed with the main algorithm. 
  // if str1[c-1] == str2[r-1] -> edit[r][c] = edit[r-1][c-1]  
  // Esto es porque al ser iguales, la unica op necesaria es la misma
  // que era necesaria en la diagonal

  // if str1[c-1] != str2[r-1] -> edit[r][c] = min(edit[r-1][c],edit[r][c-1],edit[r-1][c-1]) + 1
  // Esto es porque el numero de operaciones necesarias es el mismo que en el vecino mas proximo mas 1 

  for (int row = 1;row < editMatrix.size();++row) {
    for (int column = 1; column < editMatrix[0].size();++column) {
      if (str1[column-1] == str2[row-1]) {
        editMatrix[row][column] = editMatrix[row-1][column-1];
      } else {
        // min only takes 2 arguments so I need to use 2 nested mins
        editMatrix[row][column] = 1 + min(editMatrix[row][column-1],min(editMatrix[row-1][column],editMatrix[row-1][column-1]));
      }
    }
  }

  return editMatrix[str2.size()][str1.size()];
    
}

int main() {
  string str1 = "abc";
  string str2 = "xaac";

  cout << levenshteinDistance(str1,str2) << endl;

}