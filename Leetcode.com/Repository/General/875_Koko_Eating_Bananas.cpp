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
    int l = 1, r = *max_element(piles.begin(), piles.end());
    
    while (l < r) {
      int m = l + ((r - l) >> 1);
      
      int hour = 0;
      for (const double& pile : piles) {
        hour += ceil(pile / m);
      }
      
      if (hour <= h)
        r = m;
      else
        l = m + 1;
    }
    
    return r;
  }
};