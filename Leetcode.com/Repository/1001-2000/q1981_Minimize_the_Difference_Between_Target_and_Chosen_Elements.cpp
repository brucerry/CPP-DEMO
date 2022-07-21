// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/

#include <vector>
#include <bitset>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    bitset<4091> sumMask;
    sumMask[0] = 1;
    for (const auto& row : mat) {
      bitset<4091> tmp;
      for (const int& val : row) {
        tmp |= sumMask << val;
      }
      sumMask = tmp;
    }
    
    for (int l = target, r = target; l >= 0 or r <= 4900; l--, r++) {
      if (l >= 0 and sumMask[l])
        return abs(l - target);
      if (r <= 4900 and sumMask[r])
        return abs(r - target);
    }
    
    return -1;
  }
};