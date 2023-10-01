// https://leetcode.com/problems/maximum-odd-binary-number/

#include <string>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(), s.rend());
        swap(s[count(s.begin(), s.end(), '1') - 1], s.back());
        return s;
    }
};