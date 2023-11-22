// https://leetcode.com/problems/diagonal-traverse-ii/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> sum;
        for (int r = 0; r < nums.size(); r++) {
            for (int c = 0; c < nums[r].size(); c++) {
                if (r + c >= sum.size())
                    sum.push_back({});
                sum[r+c].emplace_back(nums[r][c]);
            }
        }
        vector<int> res;
        for (auto& row : sum) {
            for (auto it = row.rbegin(); it != row.rend(); it++) {
                res.emplace_back(*it);
            }
        }
        return res;
    }
};