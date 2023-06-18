// https://leetcode.com/problems/find-the-highest-altitude/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, cur = 0;
        for (int g : gain) {
            cur += g;
            res = max(res, cur);
        }
        return res;
    }
};