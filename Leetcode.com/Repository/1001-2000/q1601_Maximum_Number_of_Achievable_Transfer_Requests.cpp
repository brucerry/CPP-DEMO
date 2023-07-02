// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/

#include <vector>
using namespace std;

// r = size of requests
// time: O(n * 2^r)
// space: O(n + r)

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> cnt (n);
        return solve(n, requests, cnt, 0);
    }

private:
    int solve(int n, vector<vector<int>>& requests, vector<int>& cnt, int i) {
        if (i == requests.size())
            return count(cnt.begin(), cnt.end(), 0) == n ? 0 : INT_MIN;
        
        int skip = solve(n, requests, cnt, i + 1);
        cnt[requests[i][0]]--;
        cnt[requests[i][1]]++;
        int take = 1 + solve(n, requests, cnt, i + 1);
        cnt[requests[i][0]]++;
        cnt[requests[i][1]]--;
        return max(skip, take);
    }
};