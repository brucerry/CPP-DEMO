// https://leetcode.com/problems/restore-the-array/

#include <string>
#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size(), mod = 1e9 + 7;
        vector<int> dp (n + 1);
        dp.back() = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')
                continue;
            long sum = 0;
            for (int j = i; j < n and sum * 10 + s[j] - '0' <= k; j++) {
                sum = sum * 10 + s[j] - '0';
                dp[i] = (dp[i] + dp[j + 1]) % mod;
            }
        }

        return dp.front();
    }
};