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
    int charSet = 0;
    return dfs(arr, 0, charSet);
  }
  
private:
  int dfs(vector<string>& arr, int i, int& charSet) {
    if (i == arr.size())
      return countingBits(charSet);
    
    int len = 0;
    
    if (!isDuplicated(charSet, arr[i])) {
      for (const char& ch : arr[i])
        charSet |= (1 << (ch - 'a'));
      
      len = dfs(arr, i + 1, charSet);

      for (const char& ch : arr[i])
        charSet &= ~(1 << (ch - 'a'));
    }
    
    return max(len, dfs(arr, i + 1, charSet));
  }
  
  int countingBits(int n) {
    int count = 0;
    while (n) {
      n &= (n - 1);
      count++;
    }
    return count;
  }
  
  bool isDuplicated(int& charSet, string& str) {
    int strSet = 0;
    
    for (const char& ch : str) {
      if (strSet & (1 << (ch - 'a')))
        return true;
      strSet |= (1 << (ch - 'a'));
      
      if (charSet & (1 << (ch - 'a')))
        return true;
    }
    return false;
  }
};