// https://leetcode.com/problems/minimum-operations-to-collect-elements/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> uset;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] <= k)
                uset.emplace(nums[i]);
            if (uset.size() == k)
                return n - i;
        }
        return n;
    }
};