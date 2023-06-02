// https://leetcode.com/problems/detonate-the-maximum-bombs/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph (n);
        for (int i = 0; i < n; i++) {
            long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                long x2 = bombs[j][0], y2 = bombs[j][1];
                if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r1 * r1)
                    graph[i].emplace_back(j);
            }
        }

        int res = 0;
        vector<int> visited (n);
        for (int node = 0; node < n; node++) {
            fill(visited.begin(), visited.end(), 0);
            res = max(res, dfs(graph, visited, node));
        }

        return res;
    }

private:
    int dfs(vector<vector<int>>& graph, vector<int>& visited, int node) {
        if (visited[node])
            return 0;
        visited[node] = 1;
        int count = 1;
        for (auto& nei : graph[node]) {
            count += dfs(graph, visited, nei);
        }
        return count;
    }
};