#include <algorithm>
using namespace std;


//[1,4,5]
//0 +( 1 )+ (1 + 4)
// Tiempo de espera total es la suma de todos los tiempos de espera de todos los elementos
// elemento 1 tiene un tiempo de espera 0.
// Pero elemento 4 tiene tiempo de espera 0 + 1
// Y elemento 5 tiene tiempo de espera 0 + 1 + 4

// For solving this problem first sort since that is the way to minimise the waiting time, since the biggest element
// will not make wait all the others
int minimumWaitingTime(vector<int> queries) {

  std::sort(queries.begin(), queries.end());

  int waitingTime = 0;
  int numberOfElements = queries.size();

  for (int i = 1; i < queries.size();++i) {
    waitingTime += queries[i-1] * (numberOfElements - i);
  }
  return waitingTime;
}
