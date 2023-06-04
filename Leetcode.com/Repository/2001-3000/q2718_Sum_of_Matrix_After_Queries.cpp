// https://leetcode.com/problems/sum-of-matrix-after-queries/

#include <vector>
using namespace std;

// q = size of queries
// time: O(n + q)
// space: O(n)

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long res = 0, remain[2] = { n, n }, used[2][10000] = {};
        for (int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0];
            int idx = queries[i][1];
            int val = queries[i][2];
            if (used[type][idx] == 0) {
                res += remain[!type] * val;
                used[type][idx] = 1;
                remain[type]--;
            }
        }
        return res;
    }
};