// https://leetcode.com/problems/implement-queue-using-stacks/

#include <stack>
using namespace std;

// time: O(n) for pop(), O(1) for others, overall Amortized O(1) runtime
// space: O(n)

class MyQueue {
public:
  MyQueue() {
    
  }
  
  void push(int x) {
    if (tmp.empty())
      front = x;
    tmp.emplace(x);
  }
  
  int pop() {
    if (output.empty()) {
      while (tmp.size()) {
        output.emplace(tmp.top());
        tmp.pop();
      }
    }
    int val = output.top();
    output.pop();
    return val;
  }
  
  int peek() {
    if (output.size()) {
      return output.top();
    }
    return front;
  }
  
  bool empty() {
    return tmp.empty() and output.empty();
  }
  
private:
  int front;
  stack<int> tmp, output;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */