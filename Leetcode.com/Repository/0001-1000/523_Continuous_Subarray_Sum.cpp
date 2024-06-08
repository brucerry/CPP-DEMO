// https://leetcode.com/problems/continuous-subarray-sum/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> idx;
        idx[0] = -1;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            if (idx.contains(cur % k) == 0)
                idx[cur % k] = i;
            else if (i - idx[cur % k] >= 2)
                return true;
        }
        return false;
    }
};