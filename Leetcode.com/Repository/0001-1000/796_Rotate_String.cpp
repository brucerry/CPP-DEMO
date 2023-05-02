// https://leetcode.com/problems/rotate-string/

#include <string>
using namespace std;

// time: O(n + m)
// space: O(n)

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() and (s + s).find(goal) != -1;
    }
};