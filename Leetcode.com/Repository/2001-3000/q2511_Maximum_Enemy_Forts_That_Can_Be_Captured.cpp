// https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int captureForts(vector<int>& forts) {
    int res = 0, n = forts.size();
    for (int l = 0, r = 0; r < n; r++) {
      if (forts[r]) {
        if (forts[r] == -forts[l])
          res = max(res, r - l - 1);
        l = r;
      }
    }
    return res;
  }
};