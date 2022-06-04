// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#include <vector>
#include <string>
using namespace std;

// n = len of arr
// m = len of each string in arr
// time: O(2^n * m)
// space: O(n)

class Solution {
public:
  int maxLength(vector<string>& arr) {
    return solve(arr, 0, 0);
  }
  
private:
  int solve(vector<string>& arr, int i, int usedMask) {
    if (i == arr.size())
      return countingBits(usedMask);
    
    int skip = solve(arr, i + 1, usedMask);
    int apply = 0;
    
    if (!isDuplicated(arr[i], usedMask)) {
      for (const char& c : arr[i])
        usedMask |= (1 << (c - 'a'));
      apply = solve(arr, i + 1, usedMask);
    }
    
    return max(skip, apply);
  }
  
  int countingBits(int n) {
    int count = 0;
    while (n) {
      n &= n - 1;
      count++;
    }
    return count;
  }
  
  bool isDuplicated(string& s, int usedMask) {
    for (const char& c : s) {
      if (usedMask & (1 << (c - 'a')))
        return true;
      usedMask |= (1 << (c - 'a'));
    }
    return false;
  }
};