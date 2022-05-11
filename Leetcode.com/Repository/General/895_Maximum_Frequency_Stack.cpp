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
    numCount[val]++;
    if (numCount[val] > maxFreq)
      maxFreq = numCount[val];
    countGroup[numCount[val]].emplace_back(val);
  }
  
  int pop() {
    int num = countGroup[maxFreq].back();
    countGroup[maxFreq].pop_back();
    numCount[num]--;
    if (countGroup[maxFreq].size() == 0)
      maxFreq--;
    return num;
  }

private:
  int maxFreq;
  unordered_map<int, vector<int>> countGroup; // count, group members
  unordered_map<int, int> numCount; // num, count
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */