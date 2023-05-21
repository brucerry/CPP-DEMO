// https://leetcode.com/problems/maximum-split-of-positive-even-integers/

#include <vector>
using namespace std;

// time: O(sqrt(n))
// space: O(1)

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2)
            return {};
        
        vector<long long> res;
        long long cur = 2, cursum = 0;
        while (cursum + cur <= finalSum) {
            res.emplace_back(cur);
            cursum += cur;
            cur += 2;
        }

        res.back() += finalSum - cursum;

        return res;
    }
};