// https://leetcode.com/problems/trapping-rain-water/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class SpaceOptimized {
public:
  int trap(vector<int>& height) {
    int n = height.size();
    
    int water = 0;
    int l = 0, r = n - 1;
    int leftMax = height[l], rightMax = height[r];
    while (l < r) {
      if (leftMax < rightMax) {
        l++;
        leftMax = max(leftMax, height[l]);
        water += leftMax - height[l];
      }
      else {
        r--;
        rightMax = max(rightMax, height[r]);
        water += rightMax - height[r];
      }
    }
    
    return water;
  }
};

// time: O(n)
// space: O(n)
class PrefixSuffixArray {
public:
  int trap(vector<int>& height) {
    int n = height.size();
    
    vector<int> leftMax (n), rightMax(n);
    for (int i = 1; i < n; i++) {
      leftMax[i] = max(leftMax[i-1], height[i-1]);
    }
    for (int i = n - 2; i >= 1; i--) {
      rightMax[i] = max(rightMax[i+1], height[i+1]);
    }
    
    int water = 0;
    for (int i = 0; i < n; i++) {
      water += max(0, min(leftMax[i], rightMax[i]) - height[i]);
    }
    
    return water;
  }
};