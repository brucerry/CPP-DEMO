// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/

#include <vector>
#include <algorithm>
using namespace std;

// e = size of edgeList
// q = size of queries
// time: O(n + e * log(e) + q * log(q))
// space: O(n)

struct UnionFind {
    vector<int> parent;

    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.emplace_back(i);
        }
    }

    bool unions(int node1, int node2) {
        int par1 = find(node1);
        int par2 = find(node2);
        if (par1 == par2)
            return false;
        parent[par1] = par2;
        return true;
    }

    int find(int node) {
        return parent[node] == node ? node : parent[node] = find(parent[node]);
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int que_size = queries.size();
        int edge_size = edgeList.size();

        for (int i = 0; i < que_size; i++) {
            queries[i].emplace_back(i);
        }
        sort(queries.begin(), queries.end(), [](auto& q1, auto& q2) {
            return q1[2] < q2[2];
        });
        sort(edgeList.begin(), edgeList.end(), [](auto& e1, auto& e2) {
            return e1[2] < e2[2];
        });
        UnionFind uf (n);

        int i = 0;
        vector<bool> res (que_size);
        for (auto& que : queries) {
            while (i < edge_size and edgeList[i][2] < que[2]) {
                uf.unions(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            int j = que.back();
            res[j] = uf.find(que[0]) == uf.find(que[1]);
        }

        return res;
    }
};