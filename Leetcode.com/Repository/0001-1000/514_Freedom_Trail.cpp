// https://leetcode.com/problems/freedom-trail/

#include <vector>
#include <string>
using namespace std;

// r = len of ring
// k = len of key
// time: O(r^2 * k)
// space: O(r * k)

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> memo (ring.size(), vector<int>(key.size(), INT_MAX));
        return solve(ring, key, 0, 0, memo);
    }

    int solve(string& ring, string& key, int r, int k, vector<vector<int>>& memo) {
        if (k == key.size())
            return 0;
        int& res = memo[r][k];
        if (res != INT_MAX)
            return res;
        int lmove = 0, i;
        for (i = r; ring[i] != key[k]; lmove++, i = (i - 1 + ring.size()) % ring.size());
        int rmove = 0, j;
        for (j = r; ring[j] != key[k]; rmove++, j = (j + 1 + ring.size()) % ring.size());
        res = min(res, 1 + lmove + solve(ring, key, i, k + 1, memo));
        res = min(res, 1 + rmove + solve(ring, key, j, k + 1, memo));
        return res;
    }
};