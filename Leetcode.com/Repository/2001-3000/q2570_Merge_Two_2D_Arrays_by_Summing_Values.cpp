// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/

#include <vector>
using namespace std;

// time: O(n + m)
// space: O(1)

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int p1 = 0, p2 = 0;
        vector<vector<int>> res;
        while (p1 < len1 and p2 < len2) {
            if (nums1[p1][0] < nums2[p2][0])
                res.emplace_back(nums1[p1++]);
            else if (nums1[p1][0] > nums2[p2][0])
                res.emplace_back(nums2[p2++]);
            else
                res.push_back({ nums1[p1][0], nums1[p1++][1] + nums2[p2++][1] });
        }
        if (p1 < len1) {
            res.insert(res.end(), nums1.begin() + p1, nums1.end());
        }
        if (p2 < len2) {
            res.insert(res.end(), nums2.begin() + p2, nums2.end());
        }
        return res;
    }
};