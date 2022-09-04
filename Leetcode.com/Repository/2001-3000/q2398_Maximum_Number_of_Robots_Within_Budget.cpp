// https://leetcode.com/problems/maximum-number-of-robots-within-budget/

#include <vector>
#include <deque>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
    int result = 0, n = chargeTimes.size();
    long curCost = 0;
    
    deque<int> deque; // index of chargeTimes
    for (int l = 0, r = 0; r < n; r++) {
      curCost += runningCosts[r];
      while (deque.size() and chargeTimes[deque.back()] <= chargeTimes[r]) {
        deque.pop_back();
      }
      deque.emplace_back(r);
      while (deque.size() and chargeTimes[deque.front()] + (r - l + 1) * curCost > budget) {
        if (deque.size() and deque.front() == l)
          deque.pop_front();
        curCost -= runningCosts[l++];
      }
      result = max(result, r - l + 1);
    }
    
    return result;
  }
};