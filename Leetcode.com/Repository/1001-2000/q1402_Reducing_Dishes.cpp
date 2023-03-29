// https://leetcode.com/problems/reducing-dishes/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.rbegin(), sat.rend());
        int res = 0, total = 0;
        for (int s : sat) {
            total += s;
            res = max(res, res + total);
        }
        return res;
    }
};