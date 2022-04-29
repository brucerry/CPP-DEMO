// https://leetcode.com/problems/koko-eating-bananas/

#include <vector>
#include <algorithm>
using namespace std;

// n = len of piles
// m = max value of piles
// time: O(log(m) * n)
// space: O(1)

class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {    
    int k = *max_element(piles.begin(), piles.end());
    
    int l = 1, r = k;
    
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      
      int time = 0;
      for (const double& p : piles) {
        time += ceil(p / m);
      }
      
      if (time <= h) {
        r = m - 1;
        k = min(k, m);
      }
      else {
        l = m + 1;
      }
    }
    
    return k;
  }
};