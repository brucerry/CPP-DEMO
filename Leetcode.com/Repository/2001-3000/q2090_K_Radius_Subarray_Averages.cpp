// https://leetcode.com/problems/k-radius-subarray-averages/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long n = nums.size(), cursum = 0, size = k * 2 + 1;
        vector<int> res (n, -1);
        for (int l = 0, r = 0; r < n; r++) {
            cursum += nums[r];
            if (r - l + 1 == size) {
                res[l+k] = cursum / size;
                cursum -= nums[l++];
            }
        }
        return res;
    }
};