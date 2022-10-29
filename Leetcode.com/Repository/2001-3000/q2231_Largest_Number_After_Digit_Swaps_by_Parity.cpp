// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

#include <string>
#include <algorithm>
using namespace std;

// time: O(10 * log(10))
// space: O(10)

class Solution {
public:
  int largestInteger(int num) {
    string odd, even;
    for (int copy = num; copy; copy /= 10) {
      int d = copy % 10;
      d % 2 ? odd += d + '0' : even += d + '0';
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    
    string result;
    auto o = odd.begin(), e = even.begin();
    for (int copy = num; copy; copy /= 10) {
      int d = copy % 10;
      result += d % 2 ? *o++ : *e++;
    }
    
    reverse(result.begin(), result.end());
    return stoi(result);
  }
};