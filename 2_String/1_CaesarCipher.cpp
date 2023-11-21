//Advance all char in the array key positions in the alphabet

#include <string>
#include<iostream>

std::string caesarCypherEncryptor(std::string str, int key) {
  // z -a + 1 es el numero de letras en el abecedario
  if (key > 'z' - 'a' + 1) {
      key = key % ('z' - 'a' + 1);
  }

  for (auto & i  : str) {
    if(i + key <= 'z') {
      i = i + key;
    } 
    else {
      i = i + key - ('z' - 'a' + 1);
    }
  }
  return str;
}



int main() {

  std::string target = "abcd";
  std::cout << caesarCypherEncryptor(target,1) << std::endl;

  std::string target2 = "z";

  std::cout << caesarCypherEncryptor(target2,1) << std::endl;

  target2 = "kjwmntauvjjnmsagwgawkagfuaugjhawgnawgjhawjgawbfawghesh";

  std::cout << caesarCypherEncryptor(target2,15) << std::endl;

  std::cout << "z - a = " << 'z' - 'a' << std::endl;
}
