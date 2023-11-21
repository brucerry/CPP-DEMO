// https://leetcode.com/problems/count-nice-pairs-in-an-array/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int res = 0;
        for (int num : nums) {
            res = (res + cnt[num - rev(num)]++) % 1000000007;
        }
        return res;
    }

    int rev(int num) {
        int res = 0;
        while (num) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
};