// https://leetcode.com/problems/minimize-the-total-price-of-the-trips/

#include <vector>
using namespace std;

// t = size of trips
// time: O(n * t)
// space: O(n)

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> graph (n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        
        vector<int> visitcount (n);
        for (auto& t : trips) {
            int from = t[0];
            int to = t[1];
            dfs(graph, visitcount, price, -1, from, to);
        }

        vector<vector<int>> memo (2, vector<int>(n, -1));
        return min(dp(graph, visitcount, price, -1, 0, false, memo), dp(graph, visitcount, price, -1, 0, true, memo));
    }
    
private:
    int dp(vector<vector<int>>& graph, vector<int>& visitcount, vector<int>& price, int prev, int cur, bool halved, vector<vector<int>>& memo) {
        if (memo[halved][cur] != -1)
            return memo[halved][cur];

        int res = price[cur] * visitcount[cur];
        res = halved ? res / 2 : res;

        for (int& nei : graph[cur]) {
            if (nei != prev) {
                if (halved)
                    res += dp(graph, visitcount, price, cur, nei, false, memo);
                else
                    res += min(dp(graph, visitcount, price, cur, nei, false, memo),
                               dp(graph, visitcount, price, cur, nei, true, memo));
            }
        }

        return memo[halved][cur] = res;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& visitcount, vector<int>& price, int prev, int cur, int dest) {
        if (cur == dest) {
            visitcount[cur]++;
            return true;
        }
        for (int& nei : graph[cur]) {
            if (nei != prev and dfs(graph, visitcount, price, cur, nei, dest)) {
                visitcount[cur]++;
                return true;
            }
        }
        return false;
    }
};