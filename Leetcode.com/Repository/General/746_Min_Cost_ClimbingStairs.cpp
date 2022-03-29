// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int one = 0;
    int two = 0;
    int ans = min(cost[0], cost[1]);

    // one, two, ans ....

    for (int i = 2; i <= cost.size(); i++) {
      ans = min(cost[i-2] + one, cost[i-1] + two);
      one = two;
      two = ans;
    }

    return ans;
  }
};