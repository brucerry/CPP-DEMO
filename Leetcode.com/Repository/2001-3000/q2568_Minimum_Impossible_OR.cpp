// https://leetcode.com/problems/minimum-impossible-or/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> uset (nums.begin(), nums.end());
        int res = 1;
        while (uset.count(res)) {
            res <<= 1;
        }
        return res;
    }
};