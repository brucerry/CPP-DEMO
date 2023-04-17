// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxc = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for (int can : candies) {
            res.emplace_back(can + extraCandies >= maxc);
        }
        return res;
    }
};