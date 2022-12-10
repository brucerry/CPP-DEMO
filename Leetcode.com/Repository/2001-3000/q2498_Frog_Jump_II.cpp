// https://leetcode.com/problems/frog-jump-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxJump(vector<int>& stones) {
    int res = stones[1];
    for (int i = 2; i < stones.size(); i++) {
      res = max(res, stones[i] - stones[i-2]);
    }
    return res;
  }
};