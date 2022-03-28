// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <vector>
#include <numeric>
using namespace std;

// time: O(k)
// space: O(1)

class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    int l = 0, r = cardPoints.size() - k;
    int sum = accumulate(cardPoints.begin() + r, cardPoints.end(), 0);
    int ans = sum;

    while (r < cardPoints.size()) {
      sum += cardPoints[l] - cardPoints[r];
      ans = max(ans, sum);
      l++;
      r++;
    }

    return ans;
  }
};