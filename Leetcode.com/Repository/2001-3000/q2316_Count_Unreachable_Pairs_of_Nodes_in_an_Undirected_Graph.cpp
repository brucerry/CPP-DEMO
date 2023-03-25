// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#include <vector>
using namespace std;

// time: O(e + n)
// space: O(e + n)

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph (n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        vector<int> visited (n);
        long res = 1L * n * (n - 1) / 2;
        for (int node = 0; node < n; node++) {
            long count = dfs(graph, visited, node);
            res -= count * (count - 1) / 2;
        }
        return res;
    }

private:
    long dfs(vector<vector<int>>& graph, vector<int>& visited, int node) {
        if (visited[node])
            return 0;
        visited[node] = 1;
        long count = 1;
        for (const int& neighbor : graph[node]) {
            count += dfs(graph, visited, neighbor);
        }
        return count;
    }
};