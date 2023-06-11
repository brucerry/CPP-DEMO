// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

#include <vector>
using namespace std;

// l = size of left
// r = size of right
// time: O(l + r)
// space: O(1)

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for (int l : left) {
            res = max(res, l);
        }
        for (int r : right) {
            res = max(res, n - r);
        }
        return res;
    }
};