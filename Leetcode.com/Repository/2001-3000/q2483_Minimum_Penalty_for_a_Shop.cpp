// https://leetcode.com/problems/minimum-penalty-for-a-shop/

#include <string>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int bestClosingTime(string cust) {
        int n = cust.size();
        int cur = count(cust.begin(), cust.end(), 'N');
        int res = n, cost = cur;
        for (int i = n - 1; i >= 0; i--) {
            cur += cust[i] == 'Y' ? 1 : -1;
            if (cur <= cost) {
                cost = cur;
                res = i;
            }
        }
        return res;
    }
};