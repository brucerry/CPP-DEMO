// https://leetcode.com/problems/contains-duplicate/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_uset;
        for (int num : nums) {
            if (num_uset.count(num))
                return true;
            num_uset.emplace(num);
        }
        return false;
    }
};