// https://leetcode.com/problems/trapping-rain-water/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int trap(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int leftMax = height[l];
    int rightMax = height[r];
    
    int ans = 0;
    
    while (l < r) {
      if (leftMax < rightMax) {
        l++;
        leftMax = max(leftMax, height[l]);
        ans += leftMax - height[l];
      }
      else {
        r--;
        rightMax = max(rightMax, height[r]);
        ans += rightMax - height[r];
      }
    }
    
    return ans;
  }
};