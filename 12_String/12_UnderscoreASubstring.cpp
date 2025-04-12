#include<utility>
using namespace std;

string underscorifySubstring(string str, string subStr) {
  // First find matches of subStr
  vector<pair<int,int>> matches;
  int longitude = subStr.size();
  
  for (int i = 0;i<str.size();++i) {
    
    int start = str.find(subStr,i);
    if (start == string::npos) {break;}
    int end = start + longitude - 1; // In this case end is conclusive, I want the actual index where the end letter is
    matches.push_back({start,end});
  }
  // If no matches return
  if (matches.empty()) {
    return str;
  }
  
  // Second. Merged the adjacent, overlapped and neighbour intervals
  vector<pair<int,int>> mergedIntervals;
  for (int i = 0; i < matches.size();++i) {
    int start = matches[i].first;
    int end = matches[i].second;
    while( i < matches.size() - 1 && (/*matches[i+1].first <= end || */matches[i+1].first <= end + 1)) {
      end = matches[i+1].second; //end moves to the end of new interva;
      i++;
    }
    mergedIntervals.push_back({start,end});
    
  }

  // Third Add the underscore
  string solution;
  solution += str.substr(0,mergedIntervals[0].first - 0); // string = hola substr=la [2,3]. longitud = end - start
  for (int i = 0;i < mergedIntervals.size();++i) {
    int start = mergedIntervals[i].first;
    int end = mergedIntervals[i].second;
    solution += "_";
    solution += str.substr(start,end-start+1);
    solution += "_";
    if (i == mergedIntervals.size() - 1) {
      solution += str.substr(end+1);
      break;
    }
    solution += str.substr(end+1,mergedIntervals[i+1].first - (end + 1));
    
    
  }
  return solution;
}