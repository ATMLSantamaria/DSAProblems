#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Node {
 public:
  string name;
  vector<Node*> children;

  Node(string str) { name = str; }


  //Complexity T O(N+V) S O(N)    N is the number of nodes        V is the number of edges connecting the nodes
  //Why N+V We go once across all nodes so O(N) But we also iterate across all edges. So O(V). In total O (V+N)
  //Space O(N) due to the recursion
  vector<string> depthFirstSearch(vector<string>* array) {
    // Write your code here.
    Node * root = this;
    array->push_back(this->name);
    for (Node * i : children) {
      i->depthFirstSearch(array);
    }
    return *array;
  }

  Node* addChild(string name) {
    Node* child = new Node(name);
    children.push_back(child);
    return this;
  }
};

Node* createAlphabetGraph();

int main() {

  Node * myGraph = createAlphabecreateGraphtGraph();
  std::vector<std::string> res;
  res = myGraph->depthFirstSearch(&res);

  for (auto &i : res) {
    std::cout << i;
  }
  std::cout << std::endl;


}

Node* createGraph() {
    Node* root = new Node("");
    queue<Node*> q;
    q.push(root);
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            if (level < alphabet.size()) {
                Node* child = node->addChild(string(1, alphabet[level]));
                q.push(child);
            }
        }
        level++;
    }
    return root;
}

