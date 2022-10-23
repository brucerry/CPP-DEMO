// https://leetcode.com/problems/determine-if-two-events-have-conflict/

#include <vector>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
  bool haveConflict(vector<string>& event1, vector<string>& event2) {
    return event1[0] <= event2[1] and event2[0] <= event1[1];
  }
};