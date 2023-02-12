// https://leetcode.com/problems/count-the-number-of-fair-pairs/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countPairs(nums, upper) - countPairs(nums, lower - 1);
    }

private:
    long countPairs(vector<int>& nums, int val) {
        long res = 0;
        for (int l = 0, r = nums.size() - 1; l < r; l++) {
            while (l < r and nums[l] + nums[r] > val) {
                r--;
            }
            res += r - l;
        }
        return res;
    }
};