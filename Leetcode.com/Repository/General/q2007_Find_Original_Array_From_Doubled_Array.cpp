// https://leetcode.com/problems/find-original-array-from-doubled-array/

#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    if (n & 1)
      return {};
    
    sort(changed.begin(), changed.end());
    
    unordered_map<int, int> numCount;
    for (const int& num : changed)
      numCount[num]++;
    
    vector<int> originalArray;
    for (const int& num : changed) {
      if (num == 0 and numCount[num] >= 2) {
        originalArray.emplace_back(num);
        numCount[num] -= 2;
      }
      else if (num and numCount[num] and numCount.count(num << 1) and numCount[num << 1]) {
        originalArray.emplace_back(num);
        numCount[num]--;
        numCount[num << 1]--;
      }
    }
    
    return originalArray.size() == (n >> 1) ? originalArray : vector<int>();
  }
};