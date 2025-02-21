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

// T O(n) S O(1)
int GetNthFibIterative(int n) {
  // Write your code here.
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }
  int fib_n_2 = 0;
  int fib_n_1 = 1;
  int res = fib_n_2 + fib_n_1;


  //Compute F(n-1) and F(n-2)
  for (int i = 3; i <= n;++i) {
    res = fib_n_2 + fib_n_1;
   
    fib_n_2 = fib_n_1;
    fib_n_1 = res;
  }
  return res;
}


int main() {
  assert(GetNthFibRecursive(7) == 8);
  assert(GetNthFibIterative(7) == 8);

  assert(GetNthFibIterative(100000000) == GetNthFibIterative(100000000)); //here start to slow


}
