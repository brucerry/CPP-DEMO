// https://leetcode.com/problems/movement-of-robots/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L')
                nums[i] -= d;
            else
                nums[i] += d;
        }
        sort(nums.begin(), nums.end());
        long res = 0, mod = 1e9 + 7, prefix = 0;
        for (int i = 0; i < n; i++) {
            res = (res + 1L * i * nums[i] - prefix) % mod;
            prefix += nums[i];
        }
        return res;
    }
};