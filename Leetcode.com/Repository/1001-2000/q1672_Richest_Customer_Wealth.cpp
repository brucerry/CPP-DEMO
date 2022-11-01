// https://leetcode.com/problems/richest-customer-wealth/

#include <vector>
#include <numeric>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int result = 0;
    for (auto r = accounts.begin(); r != accounts.end(); r++) {
      result = max(result, accumulate(r->begin(), r->end(), 0));
    }
    return result;
  }
};