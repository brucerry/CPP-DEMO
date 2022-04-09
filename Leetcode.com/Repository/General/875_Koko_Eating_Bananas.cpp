// https://leetcode.com/problems/koko-eating-bananas/

#include <vector>
#include <algorithm>
using namespace std;

// p = # of piles
// n = max value of piles
// time: O(log(n) * p)

class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int ans = *max_element(piles.begin(), piles.end());
    
    int l = 1, r = ans;
    
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      
      int timeNeeded = 0;
      for (const int& pile : piles) {
        timeNeeded += ceil((double)pile / m);
      }
      
      if (timeNeeded <= h) {
        ans = min(ans, m);
        r = m - 1;
      }
      else {
        l = m + 1;
      }
    }
    
    return ans;
  }
};