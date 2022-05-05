// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <vector>
using namespace std;

// time: O(k)
// space: O(1)

class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    int curSum = 0;
    int l = k - 1, r = cardPoints.size() - 1;
    
    for (int i = 0; i < k; i++) {
      curSum += cardPoints[i];
    }
    
    int points = curSum;
    while (l >= 0) {
      curSum += cardPoints[r] - cardPoints[l];
      l--;
      r--;
      points = max(points, curSum);
    }
    
    return points;
  }
};