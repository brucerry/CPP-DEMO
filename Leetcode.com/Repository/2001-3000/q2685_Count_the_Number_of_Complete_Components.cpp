// https://leetcode.com/problems/count-the-number-of-complete-components/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent (n);
        for (int node = 0; node < n; node++) {
            parent[node] = node;
        }
        
        vector<int> node_count (n, 1), edge_count (n);
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            union_find(parent, node_count, edge_count, a, b);
        }
        
        int res = 0;
        for (int node = 0; node < n; node++) {
            int par = find(parent, node);
            if (par == node) {
                res += node_count[node] * (node_count[node] - 1) / 2 == edge_count[node];
            }
        }
        
        return res;
    }

private:
    void union_find(vector<int>& parent, vector<int>& node_count, vector<int>& edge_count, int n1, int n2) {
        int p1 = find(parent, n1);
        int p2 = find(parent, n2);

        edge_count[p1]++;
        
        if (p1 == p2)
            return;
        
        parent[p1] = p2;
        node_count[p2] += node_count[p1];
        edge_count[p2] += edge_count[p1];
    }
    
    int find(vector<int>& parent, int node) {
        return parent[node] == node ? node : parent[node] = find(parent, parent[node]);
    }
};