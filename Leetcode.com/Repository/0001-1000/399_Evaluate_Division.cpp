// https://leetcode.com/problems/evaluate-division/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// n = # of nodes
// e = # of edges = size of equations = size of values
// q = size of queries
// time: O(q * e)
// space: O(n + e)

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string& from = equations[i][0];
            string& to = equations[i][1];
            double& val = values[i];
            graph[from][to] = val;
            graph[to][from] = 1 / val;
        }

        vector<double> res;
        unordered_set<string> visited;
        for (auto& que : queries) {
            string& src = que[0];
            string& dst = que[1];
            double ans = 1;
            visited = {};
            res.emplace_back(dfs(graph, visited, src, dst, ans) ? ans : -1);
        }
        return res;
    }

private:
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited, const string& src, const string& dst, double& ans) {
        if (graph.count(src) == 0 or graph.count(dst) == 0)
            return false;

        if (src == dst)
            return true;

        if (visited.count(src))
            return false;

        visited.emplace(src);
        
        for (const auto& [ nei, val ] : graph[src]) {
            if (dfs(graph, visited, nei, dst, ans)) {
                ans *= val;
                return true;
            }
        }

        return false;
    }
};