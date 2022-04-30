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
  int solve(vector<string>& arr, int i, int charSet) {
    if (i == arr.size())
      return countingBits(charSet);
    
    int len = 0;
    
    if (!isDuplicated(arr[i], charSet)) {
      for (const char& c : arr[i])
        charSet |= (1 << (c - 'a'));
      
      len = solve(arr, i + 1, charSet);
      
      for (const char& c : arr[i])
        charSet &= ~(1 << (c - 'a'));
    }
    
    return max(len, solve(arr, i + 1, charSet));
  }
  
  bool isDuplicated(string& str, int charSet) {
    int tmpSet = 0;
    for (const char& c : str) {
      if (tmpSet & (1 << (c - 'a')))
        return true;
      if (charSet & (1 << (c - 'a')))
        return true;
      tmpSet |= (1 << (c - 'a'));
    }
    return false;
  }
  
  int countingBits(int n) {
    int count = 0;
    while (n) {
      n &= (n - 1);
      count++;
    }
    return count;
  }
};