// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> dp; // val, len
        int res = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int cur = arr[i];
            int next = arr[i] + diff;
            dp[cur] = dp[next] + 1;
            res = max(res, dp[cur]);
        }
        return res;
    }
};