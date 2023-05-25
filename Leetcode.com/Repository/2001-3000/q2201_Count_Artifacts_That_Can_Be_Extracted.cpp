// https://leetcode.com/problems/count-artifacts-that-can-be-extracted/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> grid (n, vector<int>(n));
        for (auto& d : dig) {
            int r = d[0];
            int c = d[1];
            grid[r][c] = 1;
        }

        int res = 0;
        for (auto& art : artifacts) {
            int r1 = art[0];
            int c1 = art[1];
            int r2 = art[2];
            int c2 = art[3];
            bool can = true;
            for (int r = r1; r <= r2; r++) {
                for (int c = c1; c <= c2; c++) {
                    can = can and grid[r][c];
                }
            }
            res += can;
        }
        return res;
    }
};