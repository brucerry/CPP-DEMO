// https://leetcode.com/problems/greatest-common-divisor-traversal/

#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

// time: O(n * sqrt(nums[i]))
// space: O(n)

struct UnionFind {
    int group;
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : group (n), parent (n), rank (n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    bool unions(int node1, int node2) {
        int par1 = find(node1);
        int par2 = find(node2);
        if (par1 == par2)
            return false;
        if (rank[par1] > rank[par2]) {
            rank[par1] += rank[par2];
            parent[par2] = par1;
        }
        else {
            rank[par2] += rank[par1];
            parent[par1] = par2;
        }
        group--;
        return true;
    }

    int find(int node) {
        return parent[node] == node ? node : parent[node] = find(parent[node]);
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        UnionFind uf (n);
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int f = 2; f * f <= num; f++) {
                if (num % f == 0) {
                    if (index.contains(f))
                        uf.unions(i, index[f]);
                    else
                        index[f] = i;
                    while (num % f == 0)
                        num /= f;
                }
            }
            if (num > 1) {
                if (index.contains(num))
                    uf.unions(i, index[num]);
                else
                    index[num] = i;
            }
        }
        return uf.group == 1;
    }
};