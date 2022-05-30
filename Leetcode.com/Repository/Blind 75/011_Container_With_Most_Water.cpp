// https://leetcode.com/problems/container-with-most-water/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    
    int water = 0;
    while (l < r) {
      if (height[l] < height[r]) {
        water = max(water, height[l] * (r - l));
        l++;
      }
      else {
        water = max(water, height[r] * (r - l));
        r--;
      }
    }
    
    return water;
  }
};