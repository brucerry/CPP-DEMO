// https://leetcode.com/problems/container-with-most-water/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    
    while (l < r) {
      if (height[l] < height[r]) {
        ans = max(ans, (r - l) * height[l]);
        l++;
      }
      else {
        ans = max(ans, (r - l) * height[r]);
        r--;
      }
    }
    
    return ans;
  }
};