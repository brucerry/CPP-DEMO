// https://leetcode.com/problems/semi-ordered-permutation/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int one_i = 0, n_i = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                one_i = i;
            else if (nums[i] == n)
                n_i = i;
        }
        return one_i + (n - n_i - 1) - (one_i > n_i);
    }
};