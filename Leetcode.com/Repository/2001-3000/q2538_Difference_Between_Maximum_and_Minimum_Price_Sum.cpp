// https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<int> graph[100001];
        for (const auto& e : edges) {
            int a = e[0];
            int b = e[1];
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        long res = 0;
        solve(graph, price, res, -1, 0);
        return res;
    }

private:
    pair<long, long> solve(vector<int>* graph, vector<int>& price, long& res, int prev, int cur) {
        pair<long, long> sums { price[cur], 0 };
        auto& [ include, not_include ] = sums;
        // include: not used as root
        // not_include: used as root
        for (const int& nei : graph[cur]) {
            if (prev != nei) {
                const auto& [ sub_include, sub_not_include ] = solve(graph, price, res, cur, nei);
                res = max(res, include + sub_not_include);
                res = max(res, not_include + sub_include);
                include = max(include, sub_include + price[cur]);
                not_include = max(not_include, sub_not_include + price[cur]);
            }
        }
        return sums;
    }
};