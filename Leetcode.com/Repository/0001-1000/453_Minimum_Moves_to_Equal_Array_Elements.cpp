// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minMoves(vector<int>& nums) {
    int minNum = *min_element(nums.begin(), nums.end());
    int move = 0;
    for (const int& num : nums) {
      move += num - minNum;
    }
    return move;
  }
};