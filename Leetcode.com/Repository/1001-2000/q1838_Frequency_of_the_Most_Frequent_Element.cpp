// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        long cur = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            cur += nums[r];
            while (1L * (r - l + 1) * nums[r] > cur + k) {
                cur -= nums[l++];
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};