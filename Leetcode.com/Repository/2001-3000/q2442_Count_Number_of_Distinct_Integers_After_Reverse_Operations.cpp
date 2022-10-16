// https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/

#include <vector>
using namespace std;

// rev = log(nums[i]) base 10
// time: O(n * rev)
// space: O(n)

class Solution {
public:
  int countDistinctIntegers(vector<int>& nums) {
    char exists[1000001] {};
    for (const int& num : nums) {
      exists[num] = 1;
      exists[rev(num)] = 1;
    }
    
    int result = 0;
    for (const char& ex : exists) {
      result += ex;
    }
    
    return result;
  }
  
private:
  int rev(int n) {
    int result = 0;
    for (; n; n /= 10) {
      result = result * 10 + n % 10;
    }
    return result;
  }
};