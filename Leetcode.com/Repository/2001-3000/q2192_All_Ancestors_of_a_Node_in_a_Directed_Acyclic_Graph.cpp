// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph (n);
        for (auto& edge : edges) {
            int& from = edge[0];
            int& to = edge[1];
            graph[from].emplace_back(to);
        }

        vector<vector<int>> res (n);
        for (int node = 0; node < n; node++) {
            dfs(graph, res, node, node);
        }

        return res;
    }

private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, int ancestor, int cur) {
        for (int nei : graph[cur]) {
            if (res[nei].size() == 0 or res[nei].back() != ancestor) {
                res[nei].emplace_back(ancestor);
                dfs(graph, res, ancestor, nei);
            }
        }
    }
};