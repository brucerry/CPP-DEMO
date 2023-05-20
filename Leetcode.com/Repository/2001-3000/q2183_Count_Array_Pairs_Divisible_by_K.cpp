// https://leetcode.com/problems/count-array-pairs-divisible-by-k/

#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

// time: O(n * sqrt(k))
// space: O(sqrt(k))

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int, long> count;
        long res = 0;
        for (int num : nums) {
            long cur_gcd = gcd(num, k);
            for (auto& [ GCD, cnt ] : count) {
                if (GCD * cur_gcd % k == 0)
                    res += cnt;
            }
            count[cur_gcd]++;
        }
        return res;
    }
};