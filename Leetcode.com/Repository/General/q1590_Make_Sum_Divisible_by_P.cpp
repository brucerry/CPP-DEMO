// https://leetcode.com/problems/make-sum-divisible-by-p/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int minSubarray(vector<int>& nums, int p) {
    int target = 0;
    for (const int& num : nums)
      target = (target + num) % p;
    
    if (target == 0)
      return 0;
    
    unordered_map<int, int> remainderIndex { // remainder, index
      { 0, -1 }
    };
    
    int n = nums.size();
    int len = n, curRemainder = 0;
    for (int i = 0; i < n; i++) {
      curRemainder = (curRemainder + nums[i]) % p;
      if (remainderIndex.count((curRemainder - target + p) % p))
        len = min(len, i - remainderIndex[(curRemainder - target + p) % p]);
      remainderIndex[curRemainder] = i;
    }
    
    return len < n ? len : -1;
  }
};