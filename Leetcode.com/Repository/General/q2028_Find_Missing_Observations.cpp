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
    for (const int& val : rolls)
      sum_m += val;
    
    int sum_n = mean * (m + n) - sum_m;
    
    if (sum_n < n or sum_n > n * 6)
      return {};
    
    vector<int> missing;
    for (int apply = 1; apply <= n; apply++) {
      int val = min(6, sum_n - (n - apply));
      missing.emplace_back(val);
      sum_n -= val;
    }
    
    return missing;
  }
};