// https://leetcode.com/problems/container-with-most-water/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int ans = 0;

    while (left < right) {
      int width = right - left;
      if (height[left] < height[right]) {
        ans = max(ans, width * height[left]);
        left++;
      }
      else {
        ans = max(ans, width * height[right]);
        right--;
      }
    }

    return ans;
  }
};