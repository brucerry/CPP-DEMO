// https://leetcode.com/problems/sliding-subarray-beauty/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int count[101] = {};
        for (int i = 0; i < k - 1; i++) {
            count[nums[i] + 50]++;
        }

        vector<int> res (nums.size() - k + 1);
        for (int l = 0, r = k - 1; r < nums.size(); l++, r++) {
            count[nums[r] + 50]++;
            int cnt_neg = 0;
            for (int i = 0; i < 50; i++) {
                cnt_neg += count[i];
                if (cnt_neg >= x) {
                    res[l] = i - 50;
                    break;
                }
            }
            count[nums[l] + 50]--;
        }

        return res;
    }
};