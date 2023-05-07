// https://leetcode.com/problems/find-the-distinct-difference-array/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        unordered_set<int> num_uset;
        for (int i = 0; i < n; i++) {
            num_uset.emplace(nums[i]);
            res.emplace_back(num_uset.size());
        }
        num_uset = {};
        for (int i = n - 1; i >= 0; i--) {
            res[i] -= num_uset.size();
            num_uset.emplace(nums[i]);
        }
        return res;
    }
};