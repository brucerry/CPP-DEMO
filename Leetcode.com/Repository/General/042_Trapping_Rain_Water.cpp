// https://leetcode.com/problems/trapping-rain-water/

#include <vector>
using namespace std;

class Solution {
public:
  // time: O(n)
  // space: O(1)
  int trap(vector<int>& height) {
    int sum = 0;
    int left = 0;
    int right = height.size() - 1;
    int maxLeft = height[left];
    int maxRight = height[right];
    while (left < right) {
      if (maxLeft < maxRight) {
        left++;
        maxLeft = max(maxLeft, height[left]);
        sum += maxLeft - height[left];
      }
      else {
        right--;
        maxRight = max(maxRight, height[right]);
        sum += maxRight - height[right];
      }
    }
    return sum;
  }
};