// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph (n);
        for (const auto& conn : connections) {
            int from = conn[0], to = conn[1];
            graph[from].emplace_back(to);
            graph[to].emplace_back(-from);
        }
        return dfs(graph, 0, 0);
    }

private:
    int dfs(vector<vector<int>>& graph, int prev, int cur) {
        int change = 0;
        for (const int& neighbor : graph[cur]) {
            if (prev != abs(neighbor))
                change += dfs(graph, cur, abs(neighbor)) + (neighbor > 0);
        }
        return change;
    }
};