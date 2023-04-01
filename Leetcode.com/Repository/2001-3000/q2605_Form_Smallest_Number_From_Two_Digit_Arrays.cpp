// https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/

#include <vector>
using namespace std;

// time: O(n + m)
// space: O(1)

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int small1 = 100, small2 = 100, common = 100;
        int mask1 = 0, mask2 = 0;
        for (int num : nums1) {
            small1 = min(small1, num);
            mask1 |= 1 << num;
        }
        for (int num : nums2) {
            small2 = min(small2, num);
            mask2 |= 1 << num;
        }
        for (int i = 0; i <= 9; i++) {
            if ((mask1 & (1 << i) and (mask2 & (1 << i))))
                common = min(common, i);
        }
        return min({
            common,
            small1 * 10 + small2,
            small2 * 10 + small1
        });
    }
};