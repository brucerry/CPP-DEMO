// https://leetcode.com/problems/relocate-marbles/

#include <vector>
#include <set>
using namespace std;

// f = size of from = size of to
// time: O(n * log(n) + f * log(n))
// space: O(n)

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& from, vector<int>& to) {
        set<int> set (nums.begin(), nums.end());
        for (int i = 0; i < from.size(); i++) {
            set.erase(from[i]);
            set.emplace(to[i]);
        }
        return vector<int>(set.begin(), set.end());
    }
};