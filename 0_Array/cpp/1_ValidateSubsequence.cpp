using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
  int it = 0;
  for (auto num : array) {

    if (num == sequence[it]) {
      it++;
    }
    if (it == sequence.size()) {
      return true;
    }
  }
  return false;
}
