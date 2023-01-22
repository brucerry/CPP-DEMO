// https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        bool t_all_zeros = true, s_all_zeros = true;
        for (int i = 0; i < s.size(); i++) {
            t_all_zeros &= target[i] == '0';
            s_all_zeros &= s[i] == '0';
        }
        return t_all_zeros == s_all_zeros;
    }
};