// https://leetcode.com/problems/counting-bits/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> ans (n + 1);
    ans[0] = 0;
    int offset = 1;
    
    for (int i = 1; i <= n ; i++) {
      if (offset << 1 == i) {
        offset = i;
      }
      ans[i] = ans[i - offset] + 1;
    }
    
    return ans;
  }
};