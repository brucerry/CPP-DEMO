// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int largestCombination(vector<int>& candidates) {
    int result = 0;
    for (int i = 0; i < 30; i++) {
      int ones = 0;
      for (const int& candidate : candidates) {
        if (candidate & (1 << i))
          ones++;
      }
      result = max(result, ones);
    }
    return result;
  }
};