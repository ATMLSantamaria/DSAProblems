#include <algorithm>
#include <cassert>

using namespace std;

//Each element in queries represent the duration of the query. HWhich is the minimum possible total waiting time?
//Just sort so the samller queries come first

int minimumWaitingTime(vector<int> queries) {
  // Write your code here.
  std::sort(queries.begin(),queries.end());
  
  int this_element_waiting_time = 0;
  int total_waiting_time = 0;
  
  for (auto & i : queries) {
    // this_element_waiting_time = total_waiting_time;
    total_waiting_time = total_waiting_time + this_element_waiting_time;

    //Update for next element
    this_element_waiting_time += i;
    
  }
  return total_waiting_time;
}

int main () {
  std::vector<int> target = {3,2,1,2,6};

  assert(minimumWaitingTime(target) == 17);

}