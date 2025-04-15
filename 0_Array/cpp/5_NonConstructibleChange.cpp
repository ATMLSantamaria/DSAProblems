#include <vector>
#include <algorithm>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  // First sort
  std::sort(coins.begin(),coins.end());

  // Iterate in the vector.
  int maxCurrentPossibleChange = 0;
  for (auto & coin : coins) {
    // If coin > maxCurrentPossibleChange + 1 -> we cannot create maxCurrentPosible Change
    // for example imagine that our first coin is 2, we cannot create 1.
    if (coin > maxCurrentPossibleChange + 1) {
      return maxCurrentPossibleChange + 1;  
    } else {
      // If coin <= maxCurrentPossibleChange + 1; it means that we can create create all possible combinations up to coin
      // So logically we can also create maxCurrentPossibleChange + coin
      maxCurrentPossibleChange += coin;
    }   
  }
  return maxCurrentPossibleChange + 1;
}
