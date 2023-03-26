// https://leetcode.com/problems/longest-cycle-in-a-graph/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> dists (n, -1);
        int res = -1, dist = 0;
        for (int node = 0; node < n; node++) {
            int cur = node, org_dist = dist;
            while (cur != -1 and dists[cur] == -1) {
                dists[cur] = dist++;
                cur = edges[cur];
            }
            if (cur != -1 and dists[cur] >= org_dist)
                res = max(res, dist - dists[cur]);
        }
        return res;
    }
};