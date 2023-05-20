// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long total = accumulate(beans.begin(), beans.end(), 0LL);
        long long res = total, n = beans.size();
        for (int i = 0; i < n; i++) {
            long long remain = beans[i] * (n - i);
            long long remove = total - remain;
            res = min(res, remove);
        }
        return res;
    }
};