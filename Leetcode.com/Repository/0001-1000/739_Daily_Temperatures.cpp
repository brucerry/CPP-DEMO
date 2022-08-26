// https://leetcode.com/problems/daily-temperatures/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class SpaceOptimized {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    
    int hottest = 0;
    vector<int> waitDays (n);
    for (int i = n - 1; i >= 0; i--) {
      if (temperatures[i] >= hottest) {
        hottest = temperatures[i];
        continue;
      }
      
      int day = 1;
      while (temperatures[i] >= temperatures[i + day])
        day += waitDays[i + day];
      
      waitDays[i] = day;
    }
    
    return waitDays;
  }
};

// time: O(n)
// space: O(n)
class MonotonicDecreasingStack {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> waitDays (n);
    
    vector<int> stack; // index
    for (int i = 0; i < n; i++) {
      while (stack.size() and temperatures[stack.back()] < temperatures[i]) {
        waitDays[stack.back()] = i - stack.back();
        stack.pop_back();
      }
      stack.emplace_back(i);
    }
    
    return waitDays;
  }
};