// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/

#include <string>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int minLength(string s) {
        string new_s;
        for (char c : s) {
            if (new_s.size() and (c == 'B' and new_s.back() == 'A' or c == 'D' and new_s.back() == 'C'))
                new_s.pop_back();
            else
                new_s += c;
        }
        return new_s.size();
    }
};