// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <vector>
using namespace std;

// time: O(k)
// space: O(1)

class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    
    int curSum = 0;
    for (int i = 0; i < k; i++)
      curSum += cardPoints[i];
    
    int score = curSum;
    int l = k - 1, r = n - 1;
    while (l >= 0) {
      curSum += cardPoints[r] - cardPoints[l];
      score = max(score, curSum);
      l--;
      r--;
    }
    
    return score;
  }
};