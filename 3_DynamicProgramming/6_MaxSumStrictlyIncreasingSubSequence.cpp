#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// array 10,    70,        20    ,     30              ,50          ,11          ,200
// sumas 10     70+10      20+10      30+20+10       50+30+20+10     11           200+50+30+20+10

// Parece obvio que empezamos calculando por la izquierda, y usamos cada resultado para evitar recalcular
// Para cada elemento, iterar hacia atras hasta encontrar el primer elemento estrictamente menor que el.
// Coger ese elemento y anadirlo a nuestro elemento

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  // I will store the results in a vector of pairs to start
  //vector<pair<int,unordered_map<int,vector<int>>>> results; // vector pairs(elemento,[suma,vector con valores]);
  int n = array.size();
  vector<int> trackingMaxSum(n);
  unordered_map<int,vector<int>> elemToVector(n);
  
  // Initialise first element
  // int elem = array[0];
  // int currentMaxSum = elem;
  
  // trackingMaxSum[0] = currentMaxSum;
  // elemToVector[elem] = {elem};
  
  for (int i = 0;i < array.size();++i) {
    // element being considered
    int elem = array[i];
    int currentMaxSum = elem;
    int reverseI = i;

    int prevIndex = -1;
    int prevMaxStrictlySmaller = INT_MIN;
    while (reverseI >= 0) {
      //The element need to be smaller than elem, bigger than prevMax, and bigger than 0
      if (array[reverseI] < elem && array[reverseI] > prevMaxStrictlySmaller && array[reverseI] > 0){
        //prevMaxStrictlySmaller = array[reverseI];
        prevMaxStrictlySmaller = trackingMaxSum[reverseI];
        prevIndex = reverseI;
      }

      reverseI--;

    }
    if (prevIndex != -1) {
      currentMaxSum += trackingMaxSum[prevIndex]; // add previous max sum of the series
      trackingMaxSum[i] = currentMaxSum; // store new max Sum of this series
      
      elemToVector[elem] = elemToVector[array[prevIndex]]; //Store the previous serie of numbers First we place the previous vector
      elemToVector[elem].push_back(elem);                 // Add this number to the series
    } else {
      trackingMaxSum[i] = currentMaxSum; // add this max sum as a start of its running series
      elemToVector[elem].push_back(elem); // Add this element as a start to its running series
    }
         
  }

  // Once you have the parallel array with maxSums and the dictionary is easy to find what we need
  int max = trackingMaxSum[0];
  int maxIndex = 0;
  for (int index = 1; index < trackingMaxSum.size();++index) {
    if (trackingMaxSum[index] > max) {
      maxIndex = index;
      max = trackingMaxSum[index];
    }
  }
  vector<vector<int>> solution;
  solution = vector<vector<int>>({{max},std::move(elemToVector[array[maxIndex]])});
  return solution;

}
