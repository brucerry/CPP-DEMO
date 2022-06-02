// https://leetcode.com/problems/missing-number/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class XOR_Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int result = n;
    
    for (int i = 0; i < n; i++) {
      result ^= i ^ nums[i];
    }
    
    return result;
  }
};

// time: O(n)
// space: O(1)
class Sum_Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int result = n;

    for (int i = 0; i < n; i++) {
      result += i - nums[i];
    }

    return result;
  }
};