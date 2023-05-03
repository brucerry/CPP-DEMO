// https://leetcode.com/problems/find-the-difference-of-two-arrays/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n + m)
// space: O(n + m)

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset1 (nums1.begin(), nums1.end());
        unordered_set<int> uset2 (nums2.begin(), nums2.end());
        vector<vector<int>> res (2);
        for (int num : uset1) {
            if (uset2.count(num) == 0) {
                res[0].emplace_back(num);
            }
        }
        for (int num : uset2) {
            if (uset1.count(num) == 0) {
                res[1].emplace_back(num);
            }
        }
        return res;
    }
};