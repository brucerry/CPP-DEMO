// https://leetcode.com/problems/maximum-frequency-stack/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(1)
// space: O(n)

class FreqStack {
public:
  FreqStack() : maxFreq(0) {
    
  }
  
  void push(int val) {
    int count = ++numCount[val];
    countNums[count].emplace_back(val);
    maxFreq = max(maxFreq, count);
  }
  
  int pop() {
    int num = countNums[maxFreq].back();
    countNums[maxFreq].pop_back();
    numCount[num]--;
    if (countNums[maxFreq].size() == 0)
      maxFreq--;
    return num;
  }
  
private:
  int maxFreq;
  unordered_map<int, int> numCount; // num, count
  unordered_map<int, vector<int>> countNums; // count, nums
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */