// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

#include <vector>
#include <algorithm>
using namespace std;

// h = size of horizontalCuts
// v = size of verticalCuts
// time: O(h * log(h) + v * log(v))
// space: O(log(h) + log(v)) for sorting

class Solution {
public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    
    int horizGap = max(horizontalCuts[0], h - horizontalCuts.back());
    for (int i = 1; i < horizontalCuts.size(); i++) {
      horizGap = max(horizGap, horizontalCuts[i] - horizontalCuts[i-1]);
    }
    
    int vertGap = max(verticalCuts[0], w - verticalCuts.back());
    for (int i = 1; i < verticalCuts.size(); i++) {
      vertGap = max(vertGap, verticalCuts[i] - verticalCuts[i-1]);
    }
    
    return (long)horizGap * vertGap % 1000000007;
  }
};