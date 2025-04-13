#include <vector>
using namespace std;

//         0                           1                                       2

// 0    0(0H,0V)                   1(1H,0V)                                 1(2H,0V)  

// 1    1(0H,1V)                  2(1H,1V)/(1V,1H)                      3(2H,1V)/(1V,2H)/(1H,1V,1H)

// 2    1(0H,2V)                3(1H,2V)/(2V,1H)/(1V,1H,1V)              6

// 3    1(0H,3V)               (1H,1V)/(1V,1H)

// 4    1(30H,4V)                  1H,1V/1V,1H


// El caso base es la primera columna y la primera fila que deben estar llenas de 1s

// Para llegar a cada casilla las formas posibles de llegar son la suma de las formas de llegar a la casilla de arriba
// mas las formas de llegar a la casilla de su izquierda. 

// Esto se ve claramente al escribir las posibilidades pero es logico ya que las unicas formas de llegar a cada casilla son
// tanto desde su casilla de arriba como desde su casilla de la derecha

// O(n*m) time O(n*m) space. This can be improved proably
int numberOfWaysToTraverseGraph(int width, int height) {

  // First create the waysMatrix of the appropiate size
  // We want width as the number of columns
  // We want height as the number of rows -> number of rows is number of elements in the first vector
  // We do not need to add 1 in this case
  int rows = height;
  int columns = width;
  vector<vector<int>> movements(rows,vector<int>(columns,0));

  // I need to populate the first row and the first colum with 1s because there is only one way to reach them. Full Horizontal or full vertical
  // populate first row
  for (int c = 0;c<columns;++c) {
    movements[0][c] = 1;
  }
  // populate first colum
  for (int r = 0;r<rows;++r) {
    movements[r][0] = 1;
  }

  // now the main algorithm
    for (int r = 1;r<rows;++r) {
      for (int c = 1;c<columns;++c) {
        movements[r][c] = movements[r-1][c] + movements[r][c-1];
      }
    }

  return movements[rows-1][columns-1];

}