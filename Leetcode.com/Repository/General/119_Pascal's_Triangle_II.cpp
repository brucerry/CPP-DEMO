// https://leetcode.com/problems/pascals-triangle-ii/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> result (rowIndex + 1);
    result[0] = result.back() = 1;
    
    for (int r = 0; r < rowIndex; r++) {
      for (int i = rowIndex - 1; i >= 1; i--) {
        result[i] += result[i-1];
      }
    }
    
    return result;
  }
};