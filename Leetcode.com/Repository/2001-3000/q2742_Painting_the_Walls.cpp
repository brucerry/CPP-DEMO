// https://leetcode.com/problems/painting-the-walls/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> memo (n, vector<int>(n + 1, INT_MAX));
        return solve(cost, time, memo, 0, n);
    }

private:
    int solve(vector<int>& cost, vector<int>& time, vector<vector<int>>& memo, int i, int walls) {
        if (walls <= 0)
            return 0;

        if (i == cost.size())
            return 1e9;
        
        int& res = memo[i][walls];
        if (res != INT_MAX)
            return res;

        res = min(res, solve(cost, time, memo, i + 1, walls));
        res = min(res, cost[i] + solve(cost, time, memo, i + 1, walls - 1 - time[i]));
        return res;
    }
};