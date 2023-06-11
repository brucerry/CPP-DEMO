// https://leetcode.com/problems/neither-minimum-nor-maximum/

#include <vector>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() <= 2)
            return -1;
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        int min_num = min({ a, b, c });
        int max_num = max({ a, b, c });
        for (int x : { a, b, c }) {
            if (min_num < x and x < max_num)
                return x;
        }
        return -1;
    }
};