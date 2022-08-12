// https://leetcode.com/problems/next-greater-element-iii/

#include <string>
#include <algorithm>
using namespace std;

// s = len of n
// time: O(s)
// space: O(s)
class Solution {
public:
  int nextGreaterElement(int n) {
    string num = to_string(n);
    int len = num.length();
    
    int i;
    for (i = len - 2; i >= 0; i--) {
      if (num[i] < num[i+1])
        break;
    }
    
    if (i == -1)
      return -1;
    
    int j;
    for (j = len - 1; num[j] <= num[i]; j--);
    
    swap(num[i], num[j]);
    reverse(num.begin() + i + 1, num.end());
    
    long result = stol(num);
    return result > INT_MAX ? -1 : result;
  }
};

// s = len of n
// time: O(s)
// space: O(s)
class NextPermutation {
public:
  int nextGreaterElement(int n) {
    string num = to_string(n);
    next_permutation(num.begin(), num.end());
    long result = stol(num);
    return result > INT_MAX or result <= n ? -1 : result;
  }
};