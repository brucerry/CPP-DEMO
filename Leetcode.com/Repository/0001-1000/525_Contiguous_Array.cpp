// https://leetcode.com/problems/contiguous-array/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> presum_index {
            { 0, -1 }
        };
        int maxlen = 0, presum = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i] ? 1 : -1;
            if (presum_index.count(presum))
                maxlen = max(maxlen, i - presum_index[presum]);
            else
                presum_index[presum] = i;
        }
        return maxlen;
    }
};