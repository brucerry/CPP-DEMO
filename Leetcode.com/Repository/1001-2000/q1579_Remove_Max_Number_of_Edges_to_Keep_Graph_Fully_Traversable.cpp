// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n + e * log(e))
// space: O(n)

struct UnionFind {
    int groups;
    vector<int> parent;

    UnionFind(int n) {
        groups = n;
        for (int i = 0; i <= n; i++) {
            parent.emplace_back(i);
        }
    }

    bool unions(int node1, int node2) {
        int par1 = find(node1);
        int par2 = find(node2);
        if (par1 == par2)
            return false;
        parent[par1] = par2;
        groups--;
        return true;
    }

    int find(int node) {
        return parent[node] == node ? node : parent[node] = find(parent[node]);
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.rbegin(), edges.rend());
        UnionFind alice (n), bob (n);

        int add = 0;
        for (auto& edge : edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            if (type == 1)
                add += alice.unions(u, v);
            else if (type == 2)
                add += bob.unions(u, v);
            else
                add += alice.unions(u, v) | bob.unions(u, v);
        }

        return alice.groups == 1 and bob.groups == 1 ? edges.size() - add : -1;
    }
};