// https://leetcode.com/problems/count-number-of-bad-pairs/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  long long countBadPairs(vector<int>& nums) {
    unordered_map<int, int> diffCount; // diff, count
    
    long long bad = 0;
    for (int i = 0; i < nums.size(); i++) {
      int diff = i - nums[i];
      bad += i - diffCount[diff];
      diffCount[diff]++;
    }
    
    return bad;
  }
};