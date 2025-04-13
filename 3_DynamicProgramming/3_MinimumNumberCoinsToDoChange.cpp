#include <vector>
#include <climits>
using namespace std;

// // if coin <= amount
//     resto = amount - coin
//     minWays = min(1 + minWays[resto],minCoins[amount];

// Para cada problema el tu restas la moneda que estas usando ya que utilizas 1. y despues sumnas el minimo numero de cambio
// para amount - esa moneda

// n=6 pesetas [1,4,5] coins
// coin 1
// min ways                     0   1   2   3   4   5   6
// amounts (index del array)    0   1   2   3   4   5   6

//coin 4
// min ways                     0   1   2   3   1   2   3
// amounts                      0   1   2   3   4   5   6



int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  vector<int> minimumNumCoins(n+1,INT_MAX-1); // to avoid overflowing the MIN_MAX in the comparison when you add 1.
  minimumNumCoins[0] = 0;
  
  for (auto coin : denoms) {
    for (int amount = 0; amount < minimumNumCoins.size();amount++) {
      if (coin <= amount) {
        int remainer = amount - coin;
        minimumNumCoins[amount] = min(minimumNumCoins[amount],1 + minimumNumCoins[remainer]);
      }
    }
  }
  // If after the process the some value was not modified, return that value
  return minimumNumCoins[n] != INT_MAX-1 ? minimumNumCoins[n] : -1;
}


int main() {

}