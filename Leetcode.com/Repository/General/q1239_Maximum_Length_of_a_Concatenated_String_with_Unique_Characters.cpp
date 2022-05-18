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
  int solve(vector<string>& arr, int i, int charMask) {
    if (i == arr.size())
      return countingBits(charMask);
    
    int skip = solve(arr, i + 1, charMask);
    int apply = 0;
    
    if (!isDuplicated(arr[i], charMask)) {
      for (const char& c : arr[i])
        charMask |= (1 << (c - 'a'));
      apply = solve(arr, i + 1, charMask);
    }
    
    return max(skip, apply);
  }
  
  bool isDuplicated(string& str, int charMask) {
    int strMask = 0;
    for (const char& c : str) {
      if (charMask & (1 << (c - 'a')))
        return true;
      if (strMask & (1 << (c - 'a')))
        return true;
      strMask |= (1 << (c - 'a'));
    }
    return false;
  }
  
  int countingBits(int charMask) {
    int count = 0;
    while (charMask) {
      charMask &= (charMask - 1);
      count++;
    }
    return count;
  }
};