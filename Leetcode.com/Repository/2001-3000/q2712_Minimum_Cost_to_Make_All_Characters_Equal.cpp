// https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    long long minimumCost(string s) {
        long long res = 0;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (s[i-1] != s[i]) {
                res += min(i, n - i);
            }
        }
        return res;
    }
};