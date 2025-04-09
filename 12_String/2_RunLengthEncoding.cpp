#include <string>
#include <iostream>
using namespace std;

string runLengthEncoding(string str) {
  // Write your code here.
  string solution;
  int counter = 0;

  for (int i = 0; i < str.size();++i) {
      counter++;
      while(i+1<str.size() && str[i+1] == str[i]) { // Important to check i+1<size to avoid accessing out of bounds element. Todo funciona, entras en while loop la ultima vez en size-1-1 pero ahi sumas 1 a i y a counter. Osea estas en i=size-1. Justo donde debes
        i++;
        counter++;
        if (counter == 9){
          solution += std::to_string(counter);
          solution += str[i];
          counter = 0;
        }
      }
      if (counter != 0) {
        solution += std::to_string(counter);
        solution += str[i];
        counter = 0;
      }

  }
  return solution;
}

int main() {
  string target = "BBBAAAAAA";
  cout << runLengthEncoding(target) << endl;
}