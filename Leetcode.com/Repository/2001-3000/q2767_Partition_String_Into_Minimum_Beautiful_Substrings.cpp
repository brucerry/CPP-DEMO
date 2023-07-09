// https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/

#include <string>
#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        vector<int> dp (n + 1, n + 1);
        dp.back() = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')
                continue;
            int mask = 0;
            for (int j = i; j < n; j++) {
                mask = (mask << 1) | (s[j] - '0');
                if (15625 % mask == 0)
                    dp[i] = min(dp[i], dp[j+1] + 1);
            }
        }
        return dp[0] > n ? -1 : dp[0];
    }
};