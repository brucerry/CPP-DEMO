// https://leetcode.com/problems/count-number-of-possible-root-nodes/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        
        vector<vector<int>> tree (n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            tree[u].emplace_back(v);
            tree[v].emplace_back(u);
        }

        vector<unordered_set<int>> guessGraph (n);
        for (const auto& guess : guesses) {
            int u = guess[0];
            int v = guess[1];
            guessGraph[u].emplace(v);
        }

        vector<int> parents (n);
        fillParent(tree, parents, 0, -1);

        int correct = 0;
        for (int node = 1; node < n; node++) {
            int parent = parents[node];
            correct += guessGraph[parent].count(node);
        }

        int res = correct >= k; // if node 0 can be root
        for (const int& child : tree[0]) {
            dfs(tree, parents, guessGraph, res, correct, child, 0, k);
        }
        return res;
    }

private:
    void dfs(vector<vector<int>>& tree, vector<int>& parents, vector<unordered_set<int>>& guessGraph, int& res, int correct, int node, int parent, int k) {
        correct += guessGraph[node].count(parent);
        correct -= guessGraph[parent].count(node);
        res += correct >= k;
        for (const int& child : tree[node]) {
            if (child != parent) {
                dfs(tree, parents, guessGraph, res, correct, child, node, k);
            }
        }
    }

    void fillParent(vector<vector<int>>& tree, vector<int>& parents, int node, int parent) {
        parents[node] = parent;
        for (const int& child : tree[node]) {
            if (child != parent) {
                fillParent(tree, parents, child, node);
            }
        }
    }
};