// https://leetcode.com/problems/maximum-frequency-stack/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(1)
// space: O(n)

class FreqStack {
public:
  FreqStack() : m_MaxCount(0) {
    
  }
  
  void push(int val) {
    int count = ++m_NumCount[val];
    m_CountGroup[count].emplace_back(val);
    if (count > m_MaxCount)
      m_MaxCount = count;
  }
  
  int pop() {
    int num = m_CountGroup[m_MaxCount].back();
    m_CountGroup[m_MaxCount].pop_back();
    m_NumCount[num]--;
    if (m_CountGroup[m_MaxCount].size() == 0)
      m_MaxCount--;
    return num;
  }

private:
  int m_MaxCount;
  unordered_map<int, vector<int>> m_CountGroup; // count, group members
  unordered_map<int, int> m_NumCount; // num, count
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */