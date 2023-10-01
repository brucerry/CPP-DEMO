// https://leetcode.com/problems/beautiful-towers-i/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long> best (n), stk { -1 };
        
        long cur = 0;
        for (int i = 0; i < n; i++) {
            while (stk.size() >= 2 and maxHeights[stk.back()] > maxHeights[i]) {
                int topi = stk.back();
                stk.pop_back();
                cur -= abs(topi - stk.back()) * maxHeights[topi];
            }
            cur += abs(i - stk.back()) * maxHeights[i];
            stk.push_back(i);
            best[i] = cur;
        }
        
        long res = 0;
        cur = 0;
        stk = { n };
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() >= 2 and maxHeights[i] < maxHeights[stk.back()]) {
                int topi = stk.back();
                stk.pop_back();
                cur -= abs(topi - stk.back()) * maxHeights[topi];
            }
            cur += abs(i - stk.back()) * maxHeights[i];
            stk.push_back(i);
            res = max(res, best[i] + cur - maxHeights[i]);
        }
        
        return res;
    }
};