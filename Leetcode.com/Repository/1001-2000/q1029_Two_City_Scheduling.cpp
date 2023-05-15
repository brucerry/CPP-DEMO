// https://leetcode.com/problems/two-city-scheduling/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto& v1, auto& v2) {
            int a1 = v1[0], b1 = v1[1];
            int a2 = v2[0], b2 = v2[1];
            return a1 - b1 < a2 - b2;
        });
        int n = costs.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2)
                res += costs[i][0];
            else
                res += costs[i][1];
        }
        return res;
    }
};