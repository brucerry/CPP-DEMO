// https://leetcode.com/problems/maximum-alternating-subsequence-sum/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  long long maxAlternatingSum(vector<int>& nums) {
    long long sumEven = 0, sumOdd = 0;
    
    for (const int& num : nums) {
      long long tmpEven = max(sumEven, sumOdd + num);
      long long tmpOdd = max(sumOdd, sumEven - num);
      
      sumEven = tmpEven;
      sumOdd = tmpOdd;
    }
    
    return sumEven;
  }
};