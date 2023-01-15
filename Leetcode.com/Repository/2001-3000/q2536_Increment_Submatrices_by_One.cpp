// https://leetcode.com/problems/increment-submatrices-by-one/

#include <vector>
using namespace std;

// q = size of queries
// time: O(n^2 + q)
// space: O(1)

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res (n, vector<int>(n));
        for (const auto& q : queries) {
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];
            res[r1][c1]++;
            if (r2 + 1 < n)
                res[r2+1][c1]--;
            if (c2 + 1 < n)
                res[r1][c2+1]--;
            if (r2 + 1 < n and c2 + 1 < n)
                res[r2+1][c2+1]++;
        }
        for (int r = 0; r < n; r++) {
            for (int c = 1; c < n; c++) {
                res[r][c] += res[r][c-1];
            }
        }
        for (int c = 0; c < n; c++) {
            for (int r = 1; r < n; r++) {
                res[r][c] += res[r-1][c];
            }
        }
        return res;
    }
};