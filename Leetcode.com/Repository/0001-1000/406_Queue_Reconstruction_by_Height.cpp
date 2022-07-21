// https://leetcode.com/problems/queue-reconstruction-by-height/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(log(n)) for sorting

class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
      return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });
    
    vector<vector<int>> queue;
    for (const auto& ppl : people) {
      queue.emplace(queue.begin() + ppl[1], ppl);
    }
    
    return queue;
  }
};