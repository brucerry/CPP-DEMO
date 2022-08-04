// https://leetcode.com/problems/mirror-reflection/

// time: O(log(q))
// space: O(1)

class Solution {
public:
  int mirrorReflection(int p, int q) {
    while (p % 2 == 0 and q % 2 == 0) {
      p /= 2;
      q /= 2;
    }
    if (p % 2 == 0)
      return 2;
    if (q % 2 == 0)
      return 0;
    return 1;
    // return 1 - p % 2 + q % 2;
  }
};