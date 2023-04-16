// https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> res;
        long curmax = 0, cursum = 0;
        for (long num : nums) {
            curmax = max(curmax, num);
            cursum += num + curmax;
            res.emplace_back(cursum);
        }
        return res;
    }
};