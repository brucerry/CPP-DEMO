// https://leetcode.com/problems/maximum-average-subarray-i/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = INT_MIN, cursum = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            cursum += nums[r];
            if (r - l + 1 > k) {
                cursum -= nums[l++];
            }
            if (r - l + 1 == k) {
                res = max(res, cursum / k);
            }
        }
        return res;
    }
};