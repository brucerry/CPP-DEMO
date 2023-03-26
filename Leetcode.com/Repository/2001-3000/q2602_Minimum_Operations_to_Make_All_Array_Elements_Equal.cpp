// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n) + q * log(n))
// space: O(n)

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long> prefix { 0 };
        for (int num : nums) {
            prefix.emplace_back(prefix.back() + num);
        }
        int n = nums.size();
        vector<long long> res;
        for (int q : queries) {
            int i = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            long largers = n - i, op_largers = prefix.back() - prefix[i] - q * largers;
            long smallers = i, op_smallers = q * smallers - prefix[i];
            res.emplace_back(op_largers + op_smallers); 
        }
        return res;
    }
};