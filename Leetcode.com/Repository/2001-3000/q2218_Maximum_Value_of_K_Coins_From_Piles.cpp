// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

#include <vector>
using namespace std;

// time: O(n * k)
// space: O(n * k)

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> memo (n, vector<int>(k + 1));
        return solve(piles, k, n, memo, 0);
    }

private:
    int solve(vector<vector<int>>& piles, int k, int n, vector<vector<int>>& memo, int i) {
        if (k == 0 or i == n)
            return 0;

        int& res = memo[i][k];

        if (res)
            return res;

        res = solve(piles, k, n, memo, i + 1);

        int take = 0;
        for (int j = 0; j < piles[i].size() and j < k; j++) {
            take += piles[i][j];
            res = max(res, take + solve(piles, k - j - 1, n, memo, i + 1));
        }

        return res;
    }
};