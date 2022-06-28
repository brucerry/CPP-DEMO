// https://leetcode.com/problems/majority-element-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int num1 = nums[0], num2 = nums[0];
    int count1 = 0, count2 = 0;
    
    for (const int& num : nums) {
      if (num == num1)
        count1++;
      else if (num == num2)
        count2++;
      else if (count1 == 0) {
        num1 = num;
        count1++;
      }
      else if (count2 == 0) {
        num2 = num;
        count2++;
      }
      else {
        count1--;
        count2--;
      }
    }
    
    count1 = count2 = 0;
    for (const int& num : nums) {
      if (num == num1)
        count1++;
      else if (num == num2)
        count2++;
    }
    
    vector<int> result;
    int n = nums.size();
    if (count1 > n / 3)
      result.emplace_back(num1);
    if (count2 > n / 3)
      result.emplace_back(num2);
    
    return result;
  }
};