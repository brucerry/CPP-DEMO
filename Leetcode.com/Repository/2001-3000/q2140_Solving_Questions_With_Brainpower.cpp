// https://leetcode.com/problems/solving-questions-with-brainpower/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp (n + 1);
        for (int i = n - 1; i >= 0; i--) {
            int point = questions[i][0];
            int brainpower = questions[i][1];
            long long next_point = i + brainpower + 1 < n ? dp[i + brainpower + 1] : 0;
            long long sum = point + next_point;
            dp[i] = max(sum, dp[i+1]);
        }
        return dp[0];
    }
};