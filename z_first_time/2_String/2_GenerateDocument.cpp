//Need to check if with the elements in characters you can create document


using namespace std;
#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>


//Solution T O(N + M) S O(N).
//Unordered map provide O(1) access so we only have the loop in characters plus the loop in document to cound. But it need O(C) memory being C the number of 
// unique characters store in the hash table
bool generateDocument(string characters, string document) {
  // Write your code here.
  if (document == "") return true;
  
  std::unordered_map<char,int> storage; //map char counter
  for (auto c : characters) {
    auto it = storage.find(c);
    if (it != storage.end()) { //That char is already there, increase counter
      storage[c] += 1;
    } else { //char is not there, so it is first appearence
      storage[c] = 1;
    }
  }

  for(auto c : document) {
    auto it = storage.find(c);
    if (it == storage.end()) {
      return false;
    } else {
      if (storage[c] == 0) {
        return false;
      }
      storage[c] -= 1;
    }
  }
  return true;
}


int main() {
  std::string characters = "rca";
  std::string document = "car";
  std::string document2 = "carcar";



  assert(generateDocument(characters,document) == true);
  assert(generateDocument(characters,document2) == false);

}