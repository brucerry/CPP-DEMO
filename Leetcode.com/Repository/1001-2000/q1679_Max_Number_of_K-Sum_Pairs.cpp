// https://leetcode.com/problems/max-number-of-k-sum-pairs/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> diff_count;
        int res = 0;
        for (int num : nums) {
            if (diff_count.count(num) and diff_count[num]) {
                res++;
                diff_count[num]--;
            }
            else
                diff_count[k - num]++;
        }
        return res;
    }
};