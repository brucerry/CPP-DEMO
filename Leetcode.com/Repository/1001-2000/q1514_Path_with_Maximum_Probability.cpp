// https://leetcode.com/problems/path-with-maximum-probability/

#include <vector>
#include <queue>
using namespace std;

// time: O(e + n * log(e))
// space: O(n + e)

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph (n); // node, p
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            graph[u].emplace_back(v, p);
            graph[v].emplace_back(u, p);
        }

        priority_queue<pair<double, int>> maxheap; // p, node
        maxheap.emplace(1, start);
        vector<double> prob (n);
        prob[start] = 1;

        while (maxheap.size()) {
            auto [ p, node ] = maxheap.top();
            maxheap.pop();
            if (node == end)
                break;
            for (auto [ nei, nei_p ] : graph[node]) {
                if (p * nei_p > prob[nei]) {
                    prob[nei] = p * nei_p;
                    maxheap.emplace(prob[nei], nei);
                }
            }
        }

        return prob[end];
    }
};