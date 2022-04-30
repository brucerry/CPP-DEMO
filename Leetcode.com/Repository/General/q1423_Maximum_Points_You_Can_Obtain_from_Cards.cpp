// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <vector>
using namespace std;

// time: O(k)
// space: O(1)

class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    int l = k - 1, r = cardPoints.size() - 1;
    
    int sum = 0;
    for (int i = 0; i < k; i++) {
      sum += cardPoints[i];
    }
    
    int score = sum;
    
    while (l >= 0) {
      sum += cardPoints[r] - cardPoints[l];
      score = max(score, sum);
      l--;
      r--;
    }
    
    return score;
  }
};