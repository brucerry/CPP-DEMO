// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/

#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }
        int res = 0;
        for (auto& [ _, c ] : cnt) {
            if (c == 1)
                return -1;
            res += ceil(c / 3.0);
        }
        return res;
    }
};