#include <vector>
using namespace std;
// 10dollars denomination [1,5,10,25]
// coin 1
// ways         [1 1 1 1 1 1 1 1 1 1 1]
// index de ways 0 1 2 3 4 5 6 7 8 9 10
// coin 5
// ways         [1 1 1 1 1 2 2 2 2 2 3]
// index de ways 0 1 2 3 4 5 6 7 8 9 10                        para 10 es 3 porque way[10-5] es way[5] que es 2
// coin 10
// ways         [1 1 1 1 1 2 2 2 2 2 4]                        ahora para 10 es 4 porqye way[10-10] es qay[0] que es 1
// index de ways 0 1 2 3 4 5 6 7 8 9 10
int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  vector<int>  ways(n+1);
  ways[0]=1;
  for (auto coin : denoms) {
    for (int amount = 0; amount < ways.size();++amount) {
      if (coin <= amount) {
        ways[amount] += ways[amount-coin];
      }
    }
  }
  return ways[n];
}
