// https://leetcode.com/problems/count-the-number-of-good-subarrays/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long res = 0, n = nums.size(), curPairs = 0;
        unordered_map<int, int> numCount; // num, count
        for (int l = 0, r = 0; r < n; r++) {
            curPairs -= countPairs(numCount[nums[r]]++);
            curPairs += countPairs(numCount[nums[r]]);
            while (curPairs >= k) {
                res += n - r;
                curPairs -= countPairs(numCount[nums[l]]--);
                curPairs += countPairs(numCount[nums[l]]);
                l++;
            }
        }
        return res;
    }

private:
    long countPairs(long count) {
        return count * (count - 1) / 2;
    }
};