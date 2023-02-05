// https://leetcode.com/problems/separate-the-digits-in-an-array/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(nums[i]))
// space: O(1)

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (; nums[i]; nums[i] /= 10) {
                res.emplace_back(nums[i] % 10);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};