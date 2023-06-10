// https://leetcode.com/problems/grid-illumination/

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// l = size of lamps
// q = size of queries
// time: O(l + q)
// space: O(n)

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> row, col, pos, neg;
        unordered_set<long> exist;

        long max_n = 1e9;
        for (auto& lamp : lamps) {
            int r = lamp[0];
            int c = lamp[1];
            if (exist.emplace(r * max_n + 1 + c).second) {
                row[r]++;
                col[c]++;
                pos[r + c]++;
                neg[r - c]++;
            }
        }

        vector<int> res;
        for (auto& q : queries) {
            int r = q[0];
            int c = q[1];
            if (row[r] or col[c] or pos[r+c] or neg[r-c]) {
                res.emplace_back(1);
                for (int x = r - 1; x <= r + 1; x++) {
                    for (int y = c - 1; y <= c + 1; y++) {
                        if (exist.erase(x * max_n + 1 + y)) {
                            row[x]--;
                            col[y]--;
                            pos[x + y]--;
                            neg[x - y]--;
                        }
                    }
                }
            }
            else {
                res.emplace_back(0);
            }
        }

        return res;
    }
};