#include <stack>
#include <cassert>
using namespace std;


//Other possible approachs imply to use a std::deque, or a std::list, or a std::vector. Indeed std::stack uses one of that underlying structures
// Also would be possible to create any structure like that ad hoc without using the std

// Feel free to add new properties and methods to the class.
class MinMaxStack {
 public:
 std::stack<int> content_;
 std::stack<int> max_stack_;
 std::stack<int> min_stack_;

  int peek() {
    // Write your code here.
    return content_.top();
  }

  int pop() {
    int number = content_.top();
    content_.pop();

    //Remove first element of both max and min stack so they still track the maximum
    max_stack_.pop();
    min_stack_.pop();

    return number;
  }

  void push(int number) {
    // Write your code here.
    content_.push(number);

    //First the case where this stacks are empty
    if (max_stack_.empty()) {
      max_stack_.push(number);
    } else {
      //Push only if bigger
      if (number > max_stack_.top()) {
        max_stack_.push(number);
      } else {
        max_stack_.push(max_stack_.top());
      }
    }

    //First the case where this stacks are empty
    if (min_stack_.empty()) {
      min_stack_.push(number);
    } else {
      //Push only if smaller
      if (number < min_stack_.top()) {
        min_stack_.push(number);
      } else {
        min_stack_.push(min_stack_.top());
      }
    }
  }

  int getMin() {
    // Write your code here.
    return min_stack_.top();
  }

  int getMax() {
    // Write your code here.
    return max_stack_.top();
  }
};

int main() {
  MinMaxStack myStack;
  myStack.push(9);
  myStack.push(1);
  myStack.push(0);
  myStack.push(3);


  assert(myStack.getMin() == 0);
  assert(myStack.getMax() == 9);
  assert(myStack.pop() == 3);
  assert(myStack.peek() == 0);
  myStack.push(100);
  assert(myStack.getMax() == 100);
  assert(myStack.pop() == 100);
  assert(myStack.getMax() == 9);


  

}