// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

#include <vector>
#include <array>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    array<int, 2> targets { tops[0], bottoms[0] };
    int n = tops.size();
    
    for (const int& target : targets) {
      int swapTop = 0;
      int swapBottom = 0;
      
      for (int i = 0; i < n; i++) {
        if (tops[i] != target and bottoms[i] != target)
          break;
        
        if (tops[i] != target)
          swapTop++;
        if (bottoms[i] != target)
          swapBottom++;
        
        if (i + 1 == n)
          return min(swapTop, swapBottom);
      }
    }
    
    return -1;
  }
};