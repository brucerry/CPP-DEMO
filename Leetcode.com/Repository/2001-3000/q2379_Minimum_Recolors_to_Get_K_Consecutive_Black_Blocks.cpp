// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minimumRecolors(string& blocks, int k) {
    int n = blocks.length(), op = n;
    for (int l = 0, r = 0, Wcount = 0; r < n; r++) {
      if (blocks[r] == 'W')
        Wcount++;
      if (r - l + 1 > k) {
        if (blocks[l] == 'W')
          Wcount--;
        l++;
      }
      if (r - l + 1 == k)
        op = min(op, Wcount);
    }
    return op;
  }
};