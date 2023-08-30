// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long res = 0, bound = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--) {
            int count = (nums[i] + bound - 1) / bound;
            res += count - 1;
            bound = nums[i] / count;
        }
        return res;
    }
};