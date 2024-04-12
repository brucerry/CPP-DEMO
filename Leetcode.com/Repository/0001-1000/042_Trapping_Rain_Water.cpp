// https://leetcode.com/problems/trapping-rain-water/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int maxleft = height.front();
        int maxright = height.back();
        for (int l = 0, r = height.size() - 1; l < r; ) {
            if (maxleft < maxright) {
                maxleft = max(maxleft, height[++l]);
                res += maxleft - height[l];
            }
            else {
                maxright = max(maxright, height[--r]);
                res += maxright - height[r];
            }
        }
        return res;
    }
};

// prefix and suffix
// time: O(n)
// space: O(n)
class Solution {
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