#include <string>

using namespace std;

string runLengthEncoding(string str) {
  // Write your code here.
  string solution;
  int counter = 0;
  for (int i = 0; i < str.size();++i) {
      counter++;
      while(str[i+1] == str[i]) {
        counter++;
        i++;
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
