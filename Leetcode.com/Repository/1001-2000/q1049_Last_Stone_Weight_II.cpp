// https://leetcode.com/problems/last-stone-weight-ii/

#include <vector>
#include <bitset>
using namespace std;

// s = sum(stones)
// time: O(n * s)
// space: O(s)

class Solution {
public:
  int lastStoneWeightII(vector<int>& stones) {
    bitset<1501> dp { 1 };
    int sum = 0;
    for (const int& stone : stones) {
      sum += stone;
      for (int s = min(1500, sum); s >= stone; s--) {
        dp[s] = dp[s] | dp[s - stone];
      }
    }
    for (int s = sum / 2; s >= 0; s--) {
      if (dp[s])
        return sum - s - s;
    }
    return 0;
  }
};