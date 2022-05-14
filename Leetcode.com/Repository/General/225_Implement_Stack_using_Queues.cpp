// https://leetcode.com/problems/implement-stack-using-queues/

#include <queue>
using namespace std;

// time: O(n) for pop(), O(1) for others
// space: O(n)

class MyStack {
public:
  MyStack() {
    
  }
  
  void push(int x) {
    queue.emplace(x);
  }
  
  int pop() {
    int size = queue.size() - 1;
    int val;
    while (size--) {
      int val = queue.front();
      queue.pop();
      queue.emplace(val);
    }
    val = queue.front();
    queue.pop();
    return val;
  }
  
  int top() {
    return queue.back();
  }
  
  bool empty() {
    return queue.size() == 0;
  }
  
private:
  queue<int> queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */