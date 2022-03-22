// https://leetcode.com/problems/daily-temperatures/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> result (temperatures.size(), 0);
    int hottest = 0;


    for (int i = temperatures.size() - 1; i >= 0; i--) {
      if (hottest <= temperatures[i]) {
        hottest = temperatures[i];
        continue;
      }

      int days = 1;
      while (temperatures[i + days] <= temperatures[i]) {
        days += result[i + days];
      }
      result[i] = days;
    }

    return result;
  }
};