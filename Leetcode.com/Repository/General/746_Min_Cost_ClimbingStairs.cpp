// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int one = 0, two = 0;
    
    for (int i = cost.size() - 1; i >= 0; i--) {
      int tmp = cost[i] + min(one, two);
      two = one;
      one = tmp;
    }
    
    return min(one, two);
  }
};