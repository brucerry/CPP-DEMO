// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res += (i * j % k == 0) and (nums[i] == nums[j]);
            }
        }
        return res;
    }
};