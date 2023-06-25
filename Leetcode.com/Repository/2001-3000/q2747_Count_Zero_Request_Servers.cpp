// https://leetcode.com/problems/count-zero-request-servers/

#include <vector>
#include <algorithm>
using namespace std;

// l = size of logs
// q = size of queries
// time: O(l * log(l) + q * log(q))
// space: O(q + log(l) + n)

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        vector<pair<int, int>> pairs; // { queries[i], i }
        int q = queries.size();
        for (int i = 0; i < q; i++) {
            pairs.emplace_back(queries[i], i);
        }
        sort(pairs.begin(), pairs.end());

        int l = 0, r = 0;
        int used = 0;
        vector<int> count (n + 1);
        vector<int> res (q);
        for (auto& [ que_time, i ] : pairs) {
            while (r < logs.size() and logs[r][1] <= que_time) {
                count[logs[r][0]]++;
                used += count[logs[r][0]] == 1;
                r++;
            }
            while (l < logs.size() and logs[l][1] < que_time - x) {
                count[logs[l][0]]--;
                used -= count[logs[l][0]] == 0;
                l++;
            }
            res[i] = n - used;
        }

        return res;
    }
};