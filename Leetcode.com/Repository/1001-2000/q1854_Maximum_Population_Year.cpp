// https://leetcode.com/problems/maximum-population-year/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> ppl (2051);
        for (auto& log : logs) {
            int birth = log[0];
            int death = log[1];
            ppl[birth]++;
            ppl[death]--;
        }
        int res = 0, max_ppl = 0;
        for (int y = 1950; y <= 2050; y++) {
            ppl[y] += ppl[y-1];
            if (ppl[y] > max_ppl) {
                res = y;
                max_ppl = ppl[y];
            }
        }
        return res;
    }
};