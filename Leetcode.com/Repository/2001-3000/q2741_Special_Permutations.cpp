// https://leetcode.com/problems/special-permutations/

#include <vector>
using namespace std;

// time: O(n * 2^n)
//space: O(n * 2^n)

class Solution {
public:
    int mod = 1e9 + 7;
    
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo (n, vector<int>(1 << n, -1));
        return solve(nums, memo, 0, 0);
    }

private:
    int solve(vector<int>& nums, vector<vector<int>>& memo, int i, int mask) {
        int n = nums.size();

        if (mask == (1 << n) - 1)
            return 1;
        
        int& res = memo[i][mask];
        if (res != -1)
            return res;
        
        res = 0;
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == 0 and (mask == 0 or nums[i] % nums[j] == 0 or nums[j] % nums[i] == 0)) {
                res = (res + solve(nums, memo, j, mask | (1 << j))) % mod;
            }
        }
        
        return res;
    }
};