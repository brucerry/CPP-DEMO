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
    vector<pair<int, int>> buffer; // temp, index
    
    vector<int> waitDays (n);
    for (int i = 0; i < n; i++) {
      while (buffer.size() and buffer.back().first < temperatures[i]) {
        int index = buffer.back().second;
        buffer.pop_back();
        waitDays[index] = i - index;
      }
      buffer.emplace_back(temperatures[i], i);
    }
    
    return waitDays;
  }
};