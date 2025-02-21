#include <string>
#include <cassert>

using namespace std;

bool isPalindrome(string str) {
  // Write your code here.
  int size_ = str.size();

  int half_size = size_ / 2;

  for (int i = 0; i < half_size;++i) {
    if (str[i] != str[size_ - 1 - i]) {
      return false;
    }
  }
  return true;
}


int main() {
  std::string first("ana"),second("hola"),third("dabalearrozalazorraelabad");

  assert(isPalindrome(first) == true);
  assert(isPalindrome(second) == false);
  assert(isPalindrome(third) == true);
}
