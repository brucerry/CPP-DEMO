// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

#include <string>
#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> memo (n, vector<int>(n, INT_MAX));
        return solve(s, memo, 0, n - 1);
    }

private:
    int solve(string& s, vector<vector<int>>& memo, int l, int r) {
        if (l >= r)
            return 0;
        
        int& res = memo[l][r];
        if (res != INT_MAX)
            return res;

        if (s[l] == s[r])
            return res = solve(s, memo, l + 1, r - 1);

        return res = 1 + min(solve(s, memo, l + 1, r), solve(s, memo, l, r - 1));
    }
};