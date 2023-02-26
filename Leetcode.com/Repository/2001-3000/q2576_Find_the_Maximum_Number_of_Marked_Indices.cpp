// https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int l = 0, r = (n + 1) / 2; r < n; r++) {
            if (2 * nums[l] <= nums[r]) {
                res += 2;
                l++;
            }
        }
        return res;
    }
};