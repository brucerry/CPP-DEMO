// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int n = tops.size();
    
    vector<int> targets { tops[0], bottoms[0] };
    
    for (const int& target : targets) {
      int topRotates = 0;
      int bottomRotates = 0;
      
      for (int i = 0; i < n; i++) {
        if (tops[i] != target and bottoms[i] != target)
          break;
        
        if (tops[i] != target)
          topRotates++;
        if (bottoms[i] != target)
          bottomRotates++;
        
        if (i + 1 == n)
          return min(topRotates, bottomRotates);
      }
    }
    
    return -1;
  }
};