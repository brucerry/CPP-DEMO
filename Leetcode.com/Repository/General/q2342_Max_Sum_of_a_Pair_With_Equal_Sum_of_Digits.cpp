// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(number of different sum of digits)

class Solution {
public:
  int maximumSum(vector<int>& nums) {
    unordered_map<int, int> sumNum; // sum of digits, max num
    
    int result = -1;
    for (const int& num : nums) {
      int sum = 0;
      for (int n = num; n; n /= 10)
        sum += n % 10;
      if (sumNum[sum])
        result = max(result, sumNum[sum] + num);
      sumNum[sum] = max(sumNum[sum], num);
    }
    
    return result;
  }
};