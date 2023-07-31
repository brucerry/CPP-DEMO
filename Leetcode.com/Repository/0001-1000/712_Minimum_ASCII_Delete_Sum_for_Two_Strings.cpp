// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

#include <string>
#include <vector>
using namespace std;

// time: O(n * m)
// space: O(n * m)

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        vector<vector<int>> memo (len1, vector<int>(len2, -1));
        vector<int> pre1 { 0 }, pre2 { 0 };
        for (char c : s1) {
            pre1.emplace_back(pre1.back() + c);
        }
        for (char c : s2) {
            pre2.emplace_back(pre2.back() + c);
        }
        return solve(s1, s2, memo, pre1, pre2, 0, 0);
    }

private:
    int solve(string& s1, string& s2, vector<vector<int>>& memo, vector<int>& pre1, vector<int>& pre2, int p1, int p2) {
        if (p1 == s1.size() and p2 == s2.size())
            return 0;

        if (p1 == s1.size())
            return pre2.back() - pre2[p2];

        if (p2 == s2.size())
            return pre1.back() - pre1[p1];

        int& res = memo[p1][p2];
        if (res != -1)
            return res;

        if (s1[p1] == s2[p2])
            return res = solve(s1, s2, memo, pre1, pre2, p1 + 1, p2 + 1);

        return res = min(s1[p1] + solve(s1, s2, memo, pre1, pre2, p1 + 1, p2), s2[p2] + solve(s1, s2, memo, pre1, pre2, p1, p2 + 1));
    }
};