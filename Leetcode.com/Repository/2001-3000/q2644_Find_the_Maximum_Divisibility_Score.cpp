// https://leetcode.com/problems/find-the-maximum-divisibility-score/

#include <vector>
using namespace std;

// n = size of nums
// d = size of divisors
// time: O(n * d)
// space: O(1)

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int res = INT_MAX, maxcount = 0;
        for (int div : divisors) {
            int count = 0;
            for (int num : nums) {
                if (num % div == 0)
                    count++;
            }
            if (count > maxcount) {
                maxcount = count;
                res = div;
            }
            else if (count == maxcount)
                res = min(res, div);
        }
        return res;
    }
};