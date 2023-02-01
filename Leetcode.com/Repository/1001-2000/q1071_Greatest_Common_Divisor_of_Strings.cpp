// https://leetcode.com/problems/greatest-common-divisor-of-strings/

#include <string>
using namespace std;

// time: O(m + n)
// space: O(m + n)

class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        return s1 + s2 == s2 + s1 ? s1.substr(0, gcd(s1.size(), s2.size())) : "";
    }
};