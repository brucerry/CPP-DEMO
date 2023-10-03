// https://leetcode.com/problems/number-of-good-pairs/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int res = 0;
        for (int num : nums) {
            if (cnt.contains(num))
                res += cnt[num];
            cnt[num]++;
        }
        return res;
    }
};