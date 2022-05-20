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
    m_Queue.emplace(x);
  }
  
  int pop() {
    int size = m_Queue.size() - 1;
    int val;
    while (size--) {
      val = m_Queue.front();
      m_Queue.pop();
      m_Queue.emplace(val);
    }
    val = m_Queue.front();
    m_Queue.pop();
    return val;
  }
  
  int top() {
    return m_Queue.back();
  }
  
  bool empty() {
    return m_Queue.size() == 0;
  }
  
private:
  queue<int> m_Queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */