// https://leetcode.com/problems/scramble-string/

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> memo;
        return solve(s1, s2, memo);
    }

private:
    bool solve(string s1, string s2, unordered_map<string, bool>& memo) {
        if (s1 == s2)
            return true;
        if (memo.count(s1 + s2))
            return memo[s1 + s2];
        bool& res = memo[s1 + s2] = false;
        int len = s1.size();
        for (int i = 1; i <= len - 1; i++) {
            bool sameOrder = solve(s1.substr(0, i), s2.substr(0, i), memo) and solve(s1.substr(i), s2.substr(i), memo);
            bool swapOrder = solve(s1.substr(0, i), s2.substr(len - i), memo) and solve(s1.substr(i), s2.substr(0, len - i), memo);
            if (sameOrder or swapOrder)
                return res = true;
        }
        return res = false;
    }
};