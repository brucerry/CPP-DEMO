// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class TwoVariables {
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

class InPlace {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    for (int i = cost.size() - 3; i >= 0; i--) {
      cost[i] += min(cost[i+1], cost[i+2]);
    }
    return min(cost[0], cost[1]);
  }
};