// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        vector<int> graph[100001];
        for (int i = 1; i < parent.size(); i++) {
            int par = parent[i], chd = i;
            graph[par].emplace_back(chd);
        }
        int res = 1;
        solve(graph, s, res, -1, 0);
        return res;
    }

private:
    int solve(vector<int>* graph, string& s, int& res, int prev, int cur) {
        int max1 = 0, max2 = 0;
        for (const int& nei : graph[cur]) {
            int childLen = solve(graph, s, res, cur, nei);
            if (s[cur] != s[nei]) {
                max2 = max(max2, childLen);
                if (max2 > max1)
                    swap(max1, max2);
            }
        }
        res = max(res, max1 + max2 + 1);
        return max1 + 1;
    }
};