// https://leetcode.com/problems/valid-parentheses/

#include <string>
#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    bool isValid(string s) {
        vector<char> vec;
        for (char c : s) {
            if (c == '(')
                vec.emplace_back(')');
            else if (c == '[')
                vec.emplace_back(']');
            else if (c == '{')
                vec.emplace_back('}');
            else {
                if (vec.empty() or vec.back() != c)
                    return false;
                vec.pop_back();
            }
        }
        return vec.empty();
    }
};