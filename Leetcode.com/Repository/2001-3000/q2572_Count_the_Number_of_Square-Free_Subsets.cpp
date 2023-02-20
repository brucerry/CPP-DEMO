// https://leetcode.com/problems/count-the-number-of-square-free-subsets/

#include <vector>
using namespace std;

// time: O(n * 1024)
// space: O(n * 1024)

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        vector<int> primes { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        vector<int> primeMasks (31, -1);
        buildMasks(primes, primeMasks);
        vector<vector<int>> memo (nums.size(), vector<int>(1 << primes.size(), -1));
        return solve(nums, primeMasks, memo, 0, 0);
    }

private:
    int solve(vector<int>& nums, vector<int>& primeMasks, vector<vector<int>>& memo, int cur, int mask) {
        if (cur >= nums.size())
            return 0;

        int& res = memo[cur][mask];
        if (res != -1)
            return res;

        int mod = 1e9+7;
        res = 0;
        res = (res + solve(nums, primeMasks, memo, cur + 1, mask)) % mod;
        if (primeMasks[nums[cur]] != -1 and (mask & primeMasks[nums[cur]]) == 0) {
            res = (res + 1 + solve(nums, primeMasks, memo, cur + 1, mask | primeMasks[nums[cur]])) % mod;
        }
        return res;
    }

    void buildMasks(vector<int>& primes, vector<int>& primeMasks) {
        for (int num = 1; num <= 30; num++) {
            int mask = 0, copy = num;
            for (int i = 0; i < primes.size(); i++) {
                if (copy % primes[i] == 0) {
                    copy /= primes[i];
                    mask |= (1 << i);
                }
            }
            if (copy == 1) {
                primeMasks[num] = mask;
            }
        }
    }
};