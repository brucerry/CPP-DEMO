// https://leetcode.com/problems/count-nice-pairs-in-an-array/

#include <vector>
#include <unordered_map>
using namespace std;

// max(nums) = 10^9
// time: O(n * log(10^9)) => O(n * 9) => O(n)
// space: O(n)

class Solution {
public:
  int countNicePairs(vector<int>& nums) {
    unordered_map<int, int> diffCount; // diff, count
    
    int nice = 0, mod = 1e9 + 7;
    for (const int& num : nums) {
      nice = (nice + diffCount[num - rev(num)]++) % mod;
    }
    return nice;
  }
  
private:
  int rev(int n) {
    int result = 0;
    for (; n; n /= 10)
      result = result * 10 + n % 10;
    return result;
  }
};