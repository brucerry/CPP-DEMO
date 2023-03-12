// https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        long prefix = 0, res = 0;
        for (const int& num : nums) {
            prefix += num;
            res += prefix > 0;
        }
        return res;
    }
};