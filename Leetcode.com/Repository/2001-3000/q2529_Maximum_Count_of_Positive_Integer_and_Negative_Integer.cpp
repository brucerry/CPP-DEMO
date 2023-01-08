// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg = upper_bound(nums.begin(), nums.end(), -1) - nums.begin();
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        return max(neg, pos);
    }
};