// https://leetcode.com/problems/greatest-common-divisor-traversal/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n * sqrt(nums[i]))
// space: O(n)

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();

        vector<int> parent (n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int groups = n;
        unordered_map<int, int> umap; // prime factor, index
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int f = 2; f * f <= num; f++) {
                if (num % f == 0) {
                    if (umap.count(f))
                        groups -= unionfind(parent, i, umap[f]);
                    else
                        umap[f] = i;
                    while (num % f == 0)
                        num /= f;
                }
            }
            if (num > 1) {
                if (umap.count(num))
                    groups -= unionfind(parent, i, umap[num]);
                else
                    umap[num] = i;
            }
        }

        return groups == 1;
    }

private:
    int unionfind(vector<int>& parent, int n1, int n2) {
        int p1 = find(parent, n1);
        int p2 = find(parent, n2);
        if (p1 == p2)
            return 0;
        parent[p1] = p2;
        return 1;
    }

    int find(vector<int>& parent, int node) {
        return parent[node] == node ? node : parent[node] = find(parent, parent[node]);
    }
};