// https://leetcode.com/problems/find-missing-observations/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    
    int sum_m = 0;
    for (const int& roll : rolls)
      sum_m += roll;
    
    int sum_n = mean * (m + n) - sum_m;
    if (n > sum_n or sum_n > 6 * n)
      return {};
    
    vector<int> missing (n);
    for (int i = 0; i < n; i++) {
      int val = min(sum_n - (n - (i + 1)), 6);
      missing[i] = val;
      sum_n -= val;
    }
    
    return missing;
  }
};