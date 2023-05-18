// https://leetcode.com/problems/sort-even-and-odd-indices-independently/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd, even;
        for (int i = 0; i < n; i++) {
            i % 2 ? odd.emplace_back(nums[i]) : even.emplace_back(nums[i]);
        }
        sort(odd.rbegin(), odd.rend());
        sort(even.begin(), even.end());
        int o = 0, e = 0;
        for (int i = 0; i < n; i++) {
            i % 2 ? nums[i] = odd[o++] : nums[i] = even[e++];
        }
        return nums;
    }
};