#include <algorithm>
#include <string>
#include <stack>
#include <iostream>
using namespace std;


//Solution with Brute force
string bestDigits(string number, int numDigits) {
  // Write your code here.

  std::stack<char> myStack;

  for (char character : number) {
    while(numDigits > 0 && !myStack.empty() && character > myStack.top()) { //int a = character - '0'. Luego si el int es mayor el char tambien es mayor
      numDigits--;
      myStack.pop();
    }
    myStack.push(character);
  }

  //Ya tengo un stack en el caso optimo. Si quedan digitos por eliminar los eliminamos de la parte de arriba, ya que eso da el caso optimo
  while(numDigits > 0) {
    numDigits--;
    myStack.pop();
  }

  //Now get the resulting string from the stack
  string res;
  while (!myStack.empty()) {
    res.push_back(myStack.top());
    myStack.pop();
  }
  reverse(res.begin(),res.end());
  
  return res;

}

int main() {

  std::cout << bestDigits(string("321"),1) << std::endl;

}


