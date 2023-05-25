// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int left = max(0, i - k);
                int right = min(n - 1, i + k);
                if (res.size()) {
                    left = max(left, res.back() + 1);
                }
                for (; left <= right; left++) {
                    res.emplace_back(left);
                }
            }
        }
        return res;
    }
};