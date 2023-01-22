// https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long plus = 0, minus = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == nums2[i])
                continue;
            int diff = nums2[i] - nums1[i];
            if (k) {
                if (diff % k)
                    return -1;
                diff /= k;
            }
            else
                return -1;
            plus += diff > 0 ? diff : 0;
            minus += diff < 0 ? diff : 0;
        }
        return plus == -minus ? plus : -1;
    }
};