// https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxnum = *max_element(nums.begin(), nums.end());
        return maxnum * k + (k - 1) * k / 2;
    }
};