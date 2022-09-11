// https://leetcode.com/problems/most-frequent-even-element/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int mostFrequentEven(vector<int>& nums) {
    unordered_map<int, int> numCount;
    
    int element = -1, maxFreq = 0;
    for (const int& num : nums) {
      if (num % 2 == 0) {
        numCount[num]++;
        if (numCount[num] > maxFreq or (numCount[num] == maxFreq and num < element)) {
          element = num;
          maxFreq = numCount[num];
        }
      }
    }
    
    return element;
  }
};