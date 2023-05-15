// https://leetcode.com/problems/sum-in-a-matrix/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(r * c * log(c))
// space: O(log(c)) for sorting

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto& row : nums) {
            sort(row.begin(), row.end());
        }
        
        int rows = nums.size();
        int cols = nums[0].size();
        int res = 0;
        for (int c = 0; c < cols; c++) {
            int maxnum = 0;
            for (int r = 0; r < rows; r++) {
                maxnum = max(maxnum, nums[r][c]);
            }
            res += maxnum;
        }
        
        return res;
    }
};