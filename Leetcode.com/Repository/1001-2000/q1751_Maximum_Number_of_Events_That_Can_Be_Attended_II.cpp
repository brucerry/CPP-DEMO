// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * k * log(n))
// space: O(n * k)

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> memo (n, vector<int>(k + 1));
        return solve(events, k, memo, 0);
    }

private:
    int solve(vector<vector<int>>& events, int k, vector<vector<int>>& memo, int i) {
        if (i == events.size() or k == 0)
            return 0;
        
        int& res = memo[i][k];
        if (res)
            return res;

        int start = events[i][0];
        int end = events[i][1];
        int val = events[i][2];

        int skip = solve(events, k, memo, i + 1);
        int j = upper_bound(events.begin() + i, events.end(), vector<int>{ end, INT_MAX, INT_MAX }) - events.begin();
        int take = val + solve(events, k - 1, memo, j);

        return res = max(skip, take);
    }
};