// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = solve(nums, target, true);
        int second = solve(nums, target, false);
        return { first, second };
    }

private:
    int solve(vector<int>& nums, int target, bool left_biased) {
        int index = -1;
        for (int l = 0, r = nums.size() - 1; l <= r; ) {
            int m = (l + r) / 2;
            if (nums[m] > target) {
                r = m - 1;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                index = m;
                if (left_biased)
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
        return index;
    }
};

class STL {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int up = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return low == nums.size() or nums[low] != target ? vector<int>{-1, -1} : vector<int>{low, up - 1};
    }
};