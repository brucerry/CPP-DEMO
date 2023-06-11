// https://leetcode.com/problems/collecting-chocolates/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        long long res = LONG_MAX;
        vector<int> org = nums;
        
        for (int move = 0; move < n; move++) {
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                nums[i] = min(nums[i], org[(i + move) % n]);
                sum += nums[i];
            }
            res = min(res, sum + 1L * move * x);
        }
        
        return res;
    }
};