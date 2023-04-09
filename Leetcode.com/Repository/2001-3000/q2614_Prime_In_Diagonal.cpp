// https://leetcode.com/problems/prime-in-diagonal/

#include <vector>
using namespace std;

// time: O(n * sqrt(max(nums)))
// space: O(1)

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (isprime(nums[i][i]))
                res = max(res, nums[i][i]);
            if (isprime(nums[i][n-i-1]))
                res = max(res, nums[i][n-i-1]);
        }
        return res;
    }

private:
    bool isprime(int num) {
        for (int f = 2; f * f <= num; f++) {
            if (num % f == 0)
                return false;
        }
        return num != 1;
    }
};