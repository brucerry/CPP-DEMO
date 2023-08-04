// https://leetcode.com/problems/sum-of-squares-of-special-elements/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (n % (i + 1) == 0) {
                res += nums[i] * nums[i];
            }
        }
        return res;
    }
};