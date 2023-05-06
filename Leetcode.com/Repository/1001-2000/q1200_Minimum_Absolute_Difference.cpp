// https://leetcode.com/problems/minimum-absolute-difference/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        vector<vector<int>> res;
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i-1];
            if (diff < min_diff) {
                min_diff = diff;
                res = { { arr[i-1], arr[i] } };
            }
            else if (diff == min_diff) {
                res.push_back({ arr[i-1], arr[i] });
            }
        }
        return res;
    }
};