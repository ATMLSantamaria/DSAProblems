#include <cassert>
using namespace std;

//Fibonacci serie is 0 1 1 2 3 5 8 ...
//GetNthFib(1) return 0 or the first numner of the serie

// T O(n) S O(n).
int GetNthFibRecursive(int n) {
  // Write your code here.
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }
  return GetNthFibRecursive(n-1) + GetNthFibRecursive(n-2);
}

int main() {
  assert(GetNthFibRecursive(7) == 8);
}
