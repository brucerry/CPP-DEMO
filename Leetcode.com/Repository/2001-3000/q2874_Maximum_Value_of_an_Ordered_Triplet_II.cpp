// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long res = 0, maxdiff = 0, maxnum = 0;
        for (long num : nums) {
            res = max(res, maxdiff * num);
            maxdiff = max(maxdiff, maxnum - num);
            maxnum = max(maxnum, num);
        }
        return res;
    }
};