// https://leetcode.com/problems/minimum-height-trees/

#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> pcnt (n);
        vector<vector<int>> graph (n);
        for (auto& e : edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
            ++pcnt[e[0]];
            ++pcnt[e[1]];
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() <= 1)
                leaves.emplace_back(i);
        }
        int remain = n;
        vector<int> tmp;
        while (remain > 2) {
            tmp = {};
            for (int l : leaves) {
                for (int nei : graph[l]) {
                    if (--pcnt[nei] == 1) {
                        tmp.emplace_back(nei);
                    }
                }
            }
            remain -= leaves.size();
            leaves = tmp;
        }
        return leaves;
    }
};