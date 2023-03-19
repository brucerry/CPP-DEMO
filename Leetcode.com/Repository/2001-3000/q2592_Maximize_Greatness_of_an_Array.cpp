// https://leetcode.com/problems/maximize-greatness-of-an-array/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i] < nums[j])
                i++;
        }
        return i;
    }
};