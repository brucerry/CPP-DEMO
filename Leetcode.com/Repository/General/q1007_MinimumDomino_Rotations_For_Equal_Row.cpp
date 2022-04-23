// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

#include <vector>
#include <array>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    array<int, 2> tryNums { tops[0], bottoms[0] };
    
    for (const int& tn : tryNums) {
      int topRotates = 0;
      int bottomRotates = 0;
      
      for (int i = 0; i < tops.size(); i++) {
        if (tops[i] != tn and bottoms[i] != tn)
          break;
        if (tops[i] != tn)
          topRotates++;
        if (bottoms[i] != tn)
          bottomRotates++;
        
        if (i + 1 == tops.size())
          return min(topRotates, bottomRotates);
      }
    }
    
    return -1;
  }
};