// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts (n + 1);
        vector<vector<int>> res;
        for (int num : nums) {
            if (res.size() <= counts[num])
                res.push_back({});
            res[counts[num]++].push_back(num);
        }
        return res;
    }
};