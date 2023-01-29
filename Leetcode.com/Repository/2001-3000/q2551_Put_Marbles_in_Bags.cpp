// https://leetcode.com/problems/put-marbles-in-bags/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        for (int i = 0; i < n - 1; i++) {
            weights[i] += weights[i+1];
        }
        weights.pop_back();
        sort(weights.begin(), weights.end());
        long res = 0;
        k--;
        for (int l = 0, r = n - 2; k; k--) {
            res += weights[r] - weights[l];
            l++, r--;
        }
        return res;
    }
};