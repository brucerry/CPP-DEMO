// https://leetcode.com/problems/min-stack/

#include <stack>
using namespace std;

// time: O(1) for the operations
// space: O(n)

class MinStack {
public:
  MinStack() {
    
  }
  
  void push(int val) {
    if (stack.size())
      stack.emplace(val, min(val, getMin()));
    else
      stack.emplace(val, val);
  }
  
  void pop() {
    stack.pop();
  }
  
  int top() {
    return stack.top().first;
  }
  
  int getMin() {
    return stack.top().second;
  }
  
private:
  stack<pair<int, int>> stack; // val, curMin
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */