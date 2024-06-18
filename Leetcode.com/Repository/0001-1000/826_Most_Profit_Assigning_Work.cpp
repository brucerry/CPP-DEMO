// https://leetcode.com/problems/most-profit-assigning-work/

#include <vector>
#include <map>
using namespace std;

// n = size of difficulty and profit
// w = size of worker
// time: O(n * log(n) + w * log(n))
// space: O(n)

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int> pt;
        for (int i = 0; i < profit.size(); i++) {
            pt[difficulty[i]] = max(pt[difficulty[i]], profit[i]);
        }
        int prev = 0;
        for (auto& [ _, p ] : pt) {
            prev = p = max(prev, p);
        }
        int res = 0;
        for (int w : worker) {
            res += (--pt.upper_bound(w))->second;
        }
        return res;
    }
};