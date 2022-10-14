// https://leetcode.com/problems/count-lattice-points-inside-a-circle/

#include <vector>
using namespace std;

// time: O(n * x * y)
// space: O(1)

class Solution {
public:
  int countLatticePoints(vector<vector<int>>& circles) {
    int result = 0;
    for (int x = 0; x <= 200; x++) {
      for (int y = 0; y <= 200; y++) {
        for (const auto& cir : circles) {
          int a = cir[0], b = cir[1], r = cir[2];
          if ((a - x) * (a - x) + (b - y) * (b - y) <= r * r) {
            result++;
            break;
          }
        }
      }
    }
    return result;
  }
};