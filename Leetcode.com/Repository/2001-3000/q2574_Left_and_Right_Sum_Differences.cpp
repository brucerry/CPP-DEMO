// https://leetcode.com/problems/left-and-right-sum-differences/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int leftsum = 0, rightsum = accumulate(nums.begin(), nums.end(), 0);
        for (const int& num : nums) {
            rightsum -= num;
            res.emplace_back(abs(rightsum - leftsum));
            leftsum += num;
        }
        return res;
    }
};