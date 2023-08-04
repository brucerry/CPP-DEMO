// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int line[300005] {};
        for (int num : nums) {
            line[num - k + 100000]++;
            line[num + k + 100000 + 1]--;
        }
        int res = 0;
        for (int i = 1; i < 300005; i++) {
            line[i] += line[i-1];
            res = max(res, line[i]);
        }
        return res;
    }
};