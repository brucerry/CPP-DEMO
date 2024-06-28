// https://leetcode.com/problems/maximum-total-importance-of-roads/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n) + e)
// space: O(n)

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cnt (n);
        for (auto& r : roads) {
            ++cnt[r[0]];
            ++cnt[r[1]];
        }
        sort(cnt.begin(), cnt.end());
        long res = 0;
        for (int i = 0; i < n; i++) {
            res += 1L * (i + 1) * cnt[i];
        }
        return res;
    }
};