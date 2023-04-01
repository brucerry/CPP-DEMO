// https://leetcode.com/problems/shortest-cycle-in-a-graph/

#include <vector>
#include <queue>
using namespace std;

// time: O(n^2)
// space: O(n + e)

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph (n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int res = 10000;
        for (int node = 0; node < n; node++) {
            res = min(res, bfs(graph, node));
        }

        return res == 10000 ? -1 : res;
    }

private:
    int bfs(vector<vector<int>>& graph, int node) {
        int n = graph.size();
        vector<int> dis (n, -1);
        dis[node] = 0;

        queue<int> queue ({ node });
        while (queue.size()) {
            int cur = queue.front();
            queue.pop();
            for (int nei : graph[cur]) {
                if (dis[nei] == -1) {
                    dis[nei] = dis[cur] + 1;
                    queue.push(nei);
                }
                else if (dis[nei] >= dis[cur])
                    return dis[nei] + dis[cur] + 1;
            }
        }
        return 10000;
    }
};