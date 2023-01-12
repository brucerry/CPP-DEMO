// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

#include <vector>
#include <string>
#include <cstring>
using namespace std;

// time: O(n * 26)
// space: O(n * 26)

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> graph[100001];
        for (const auto& e : edges) {
            int a = e[0], b = e[1];
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        vector<int> res (n);
        solve(graph, labels, res, -1, 0);
        return res;
    }

private:
    int* solve(vector<int>* graph, string& labels, vector<int>& res, int prev, int cur) {
        int* counts = new int[26];
        memset(counts, 0, 26 * sizeof(int));
        counts[labels[cur] - 'a'] = 1;
        for (const int& nei : graph[cur]) {
            if (nei != prev) {
                int* childcounts = solve(graph, labels, res, cur, nei);
                for (int i = 0; i < 26; i++) {
                    counts[i] += childcounts[i];
                }
            }
        }
        res[cur] = counts[labels[cur] - 'a'];
        return counts;
    }
};