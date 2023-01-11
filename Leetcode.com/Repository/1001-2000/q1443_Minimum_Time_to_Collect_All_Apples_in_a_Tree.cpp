// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> graph[100001];
        for (const auto& e : edges) {
            int a = e[0], b = e[1];
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        return 2 * max(0, solve(graph, hasApple, -1, 0) - 1);
    }

private:
    int solve(vector<int>* graph, vector<bool>& hasApple, int prev, int cur) {
        int res = 0;
        for (const int& nei : graph[cur]) {
            if (nei != prev) {
                res += solve(graph, hasApple, cur, nei);
            }
        }
        return res ? res + 1 : hasApple[cur];
    }
};