// https://leetcode.com/problems/make-k-subarray-sums-equal/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long n = arr.size(), res = 0;
        vector<int> cycle;
        for (int i = 0; i < n; i++) {
            cycle = {};
            for (int j = i; arr[j]; j = (j + k) % n) {
                cycle.push_back(arr[j]);
                arr[j] = 0;
            }
            nth_element(cycle.begin(), cycle.begin() + cycle.size() / 2, cycle.end());
            int median = cycle[cycle.size() / 2];
            for (int num : cycle) {
                res += abs(num - median);
            }
        }
        return res;
    }
};