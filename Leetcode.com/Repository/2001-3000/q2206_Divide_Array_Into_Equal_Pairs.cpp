// https://leetcode.com/problems/divide-array-into-equal-pairs/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int count[501] {};
        for (int num : nums) {
            count[num]++;
        }
        for (int cnt : count) {
            if (cnt & 1)
                return false;
        }
        return true;
    }
};