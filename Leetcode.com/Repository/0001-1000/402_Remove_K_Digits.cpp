// https://leetcode.com/problems/remove-k-digits/

#include <string>
#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for (char c : num) {
            while (res.size() and res.back() > c and k) {
                res.pop_back();
                k--;
            }
            res += c;
        }
        int i = 0;
        while (i < res.size() and res[i] == '0') {
            i++;
        }
        while (k and res.size()) {
            res.pop_back();
            k--;
        }
        return i < res.size() ? res.substr(i) : "0";
    }
};