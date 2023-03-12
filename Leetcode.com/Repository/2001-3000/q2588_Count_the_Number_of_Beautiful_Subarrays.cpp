// https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<long, long> maskcount {
            { 0, 1 }
        };
        long res = 0, curmask = 0;
        for (const int& num : nums) {
            curmask ^= num;
            res += maskcount[curmask]++;
        }
        return res;
    }
};