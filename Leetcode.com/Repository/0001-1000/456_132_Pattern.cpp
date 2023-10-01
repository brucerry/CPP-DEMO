// https://leetcode.com/problems/132-pattern/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int nums_k = INT_MIN;
        vector<int> stk;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (stk.size() and nums[stk.back()] < nums[i]) {
                nums_k = nums[stk.back()];
                stk.pop_back();
            }
            stk.emplace_back(i);
            if (nums[i] < nums_k)
                return true;
        }
        return false;
    }
};