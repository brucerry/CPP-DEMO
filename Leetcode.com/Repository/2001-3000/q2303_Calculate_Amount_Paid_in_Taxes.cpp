// https://leetcode.com/problems/calculate-amount-paid-in-taxes/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  double calculateTax(vector<vector<int>>& brackets, int income) {
    double result = 0;
    for (int i = 0; i < brackets.size(); i++) {
      int& upper = brackets[i][0];
      int& percent = brackets[i][1];
      upper = min(upper, income);
      double dollars = upper;
      if (i)
        dollars -= brackets[i-1][0];
      result += dollars * percent / 100;
    }
    return result;
  }
};