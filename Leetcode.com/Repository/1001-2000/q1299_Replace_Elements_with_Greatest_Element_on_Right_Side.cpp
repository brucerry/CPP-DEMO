// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

#include <vector>
#include <utility>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> replaceElements(vector<int>& arr) {
    int curMax = -1;
    for (auto it = arr.rbegin(); it != arr.rend(); it++) {
      curMax = max(curMax, exchange(*it, curMax));
    }
    return arr;
  }
};