// https://leetcode.com/problems/daily-temperatures/

#include <vector>
#include <stack>
using namespace std;

// time: O(n)
// space: O(1)
class OptimizedSpace {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {    
    vector<int> daysToWait (temperatures.size());
    
    int hottest = 0;
    
    for (int i = temperatures.size() - 1; i >= 0; i--) {
      if (temperatures[i] >= hottest) {
        hottest = temperatures[i];
        continue;
      }
      
      int days = 1;
      
      while (temperatures[i + days] <= temperatures[i]) {
        days += daysToWait[i + days];
      }
      
      daysToWait[i] = days;
    }
    
    return daysToWait;
  }
};

// time: O(n)
// space: O(n)
class MonotonicDecreasingStack {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> daysToWait (temperatures.size(), 0);
    
    stack<pair<int, int>> stack; // (index, temp)
    
    for (int i = 0; i < temperatures.size(); i++) {
      while (stack.size() and temperatures[i] > stack.top().second) {
        daysToWait[stack.top().first] = i - stack.top().first;
        stack.pop();
      }
      stack.emplace(i, temperatures[i]);
    }
    
    return daysToWait;
  }
};