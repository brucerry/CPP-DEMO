// https://leetcode.com/problems/two-furthest-houses-with-different-colors/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxDistance(vector<int>& colors) {
    int n = colors.size(), l = 0, r = n - 1;
    
    while (colors.front() == colors[r])
      r--;
    
    while (colors[l] == colors.back())
      l++;
    
    return max(n - 1 - l, r);
  }
};