#include <algorithm>
#include <string>
#include <iostream>
#include <list>

using namespace std;

string reverseWordsInString(string str) {
  // First reverse full string
  std::reverse(str.begin(),str.end());

  // Now reverse each word in the resulting string using slow and fast iterator
  auto slowIt = str.begin();
  
  for (auto it = str.begin();it < str.end();++it) {
    // If the end of the string is reached or a space is reached reverse the word (the last word)
    if ( (it+1) == str.end() || *(it+1) == ' ') { // do not use checks against \0 in c++ strings, only in C. Better the .end()
      std::reverse(slowIt,it+1);
      // Move it forward
      it++;
      // Reset slowIt
      slowIt=it;
    }

    // If we are in a space move both iterators unreach the beginning of the new word or the end of the string
    while(it != str.end() && *it == ' ') { // avoid the while loop to reach str.end()
      it++;
      slowIt=it;
    }
  }
  return str;
}

void reverseList(list<string> & target) {
  if (target.empty()) {
    return;
  }
  
  list<string>::iterator left = target.begin();
  list<string>::iterator right = target.end();
  right--;// You dont want to swap end since it is not one of the values of the list
  
  while (left != right) {  //iterators of a list cannot be compared with left < right since they are not positional
    std::swap(*left,*right);
    if (std::next(left) == right) {
      break;
    }
    left++;
    right--;
  }
  
}


string reverseWordsInStringWithList(string str) {
  // List
  std::list<string> listToReverse;
  string solution;

  // Move forward in the string with 2 iterators, locate the words and append them to a list
  string::iterator it;

  string segment;

  for (it = str.begin();it < str.end();++it) {
    segment += *it;

    // If both char non ' ' or both char are ' ' this return false. otherwise true
    auto changeSegment =   [](char a, char b) {
                            return !((a != ' ' && b != ' ' ) || a == b); 
                            };
    // If true, this segment end. Append to the list. Reset the segment
    if (it == str.end() - 1 || changeSegment(*it,*(it+1))) {
      listToReverse.push_back(segment);
      segment.clear();
    }
  }

  reverseList(listToReverse);

  for (auto & str : listToReverse) {
    solution += std::move(str);
  }

  return solution;
  
}


int main() {
  string target = "has a ";
  string start = "--";
  string end = "---";

  cout << (string("---") += reverseWordsInString(target)+= string("---")) << endl;
}