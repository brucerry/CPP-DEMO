// https://leetcode.com/problems/similar-string-groups/

#include <vector>
#include <string>
using namespace std;

// n = size of strs
// m = size of strs[i]
// time: O(n^2 * m)
// space: O(n)

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        int parent[300] = {};
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int groups = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j]))
                    groups -= unionFind(strs, parent, i, j);
            }
        }

        return groups;
    }

private:
    int find(int* parent, int node) {
        return parent[node] == node ? node : parent[node] = find(parent, parent[node]);
    }

    bool unionFind(vector<string>& strs, int* parent, int node1, int node2) {
        int par1 = find(parent, node1);
        int par2 = find(parent, node2);
        if (par1 == par2)
            return 0;
        parent[par1] = par2;
        return 1;
    }

    bool isSimilar(string& s1, string& s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            diff += s1[i] != s2[i];
        }
        return diff <= 2;
    }
};