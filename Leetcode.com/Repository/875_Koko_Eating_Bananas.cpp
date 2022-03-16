// https://leetcode.com/problems/koko-eating-bananas/

#include <vector>
#include <algorithm>
using namespace std;

// p = len of piles
// n = max value of piles
// time: O(log(n) * p)

class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int k = right;

    while (left <= right) {
      int tryK = left + ((right - left) >> 1);
      int tryH = 0;
      for (int& num : piles) {
        tryH += ceil((double)num / tryK);
      }
      if (tryH <= h) {
        k = min(k, tryK);
        right = tryK - 1;
      }
      else {
        left = tryK + 1;
      }
    }

    return k;
  }
};