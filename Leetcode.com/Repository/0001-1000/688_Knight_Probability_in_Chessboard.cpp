// https://leetcode.com/problems/knight-probability-in-chessboard/

#include <vector>
#include <cstring>
using namespace std;

// time: O(n^2 * k)
// space: O(n^2 * k)

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        double memo[25][25][101];
        memset(memo, -1, sizeof(memo));
        vector<pair<int, int>> moves {
            { 1, 2 },
            { 2, 1 },
            { -1, 2 },
            { -2, 1 },
            { -1, -2 },
            { -2, -1 },
            { 1, -2 },
            { 2, -1 },
        };
        return solve(n, k, row, column, memo, moves);
    }

private:
    double solve(int n, int k, int r, int c, double (*memo)[25][101], vector<pair<int, int>>& moves) {
        if (k == 0)
            return 1;

        double& res = memo[r][c][k];
        if (res >= 0)
            return res;

        res = 0;
        for (auto& [ dr, dc ] : moves) {
            int newr = r + dr;
            int newc = c + dc;
            if (min(newr, newc) >= 0 and max(newr, newc) < n) {
                res += 1.0 / 8.0 * solve(n, k - 1, newr, newc, memo, moves);
            }
        }

        return res;
    }
};