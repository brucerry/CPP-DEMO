// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/

#include <string>
#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        
        vector<int> parentCount (n);
        vector<vector<int>> graph (n);
        for (const auto& e : edges) {
            int from = e[0], to = e[1];
            graph[from].emplace_back(to);
            parentCount[to]++;
        }
        
        vector<vector<int>> count (n, vector<int>(26));
        vector<int> ready;
        for (int node = 0; node < n; node++) {
            if (parentCount[node] == 0) {
                ready.emplace_back(node);
                int color = colors[node] - 'a';
                count[node][color]++;
            }
        }

        int res = 0, visitedCount = 0;
        while (ready.size()) {
            int node = ready.back();
            ready.pop_back();

            res = max(res, count[node][colors[node] - 'a']);
            visitedCount++;

            for (int nei : graph[node]) {
                int color = colors[nei] - 'a';
                for (int c = 0; c < 26; c++) {
                    count[nei][c] = max(count[nei][c], count[node][c] + (c == color));
                }
                if (--parentCount[nei] == 0)
                    ready.emplace_back(nei);
            }
        }

        return visitedCount < n ? -1 : res;
    }
};