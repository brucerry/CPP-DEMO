// https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long sum = accumulate(nums.begin(), nums.end(), 0L);
        long n = nums.size();
        long q = target / sum;
        long need = n * q;
        target %= sum;
        long cur = 0, len = INT_MAX;
        for (long l = 0, r = 0; r < 2 * n; r++) {
            cur += nums[r % n];
            while (cur > target) {
                cur -= nums[l % n];
                l++;
            }
            if (cur == target)
                len = min(len, r - l + 1);
        }
        return len == INT_MAX ? -1 : len + need;
    }
};