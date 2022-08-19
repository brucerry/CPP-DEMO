// https://leetcode.com/problems/split-array-into-consecutive-subsequences/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int, int> numCount, tails;
    for (const int& num : nums)
      numCount[num]++;
    
    for (const int& num : nums) {
      if (numCount[num] == 0)
        continue;
      numCount[num]--;
      if (tails.count(num - 1) and tails[num - 1]) {
        tails[num - 1]--;
        tails[num]++;
      }
      else if (numCount.count(num + 1) and numCount.count(num + 2) and numCount[num + 1] and numCount[num + 2]) {
        numCount[num + 1]--;
        numCount[num + 2]--;
        tails[num + 2]++;
      }
      else
        return false;
    }
    
    return true;
  }
};