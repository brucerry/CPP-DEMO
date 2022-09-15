// https://leetcode.com/problems/find-original-array-from-doubled-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    
    if (n % 2)
      return {};
    
    int numCount[100001] {};
    for (const int& num : changed) {
      numCount[num]++;
    }
    
    vector<int> result;
    for (int num = 0; num <= 100000; num++) {
      if (numCount[num] == 0)
        continue;
      
      if (num == 0) {
        result.insert(result.end(), numCount[num] / 2, num);
      }
      else if (num * 2 <= 100000 and numCount[num * 2] >= numCount[num]) {
        result.insert(result.end(), numCount[num], num);
        numCount[num * 2] -= numCount[num];
      }
    }
    
    return result.size() == n / 2 ? result : vector<int>();
  }
};