// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <vector>
#include <string>
using namespace std;

// time: O(4^n)
// space: O(n)

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        string strings[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> res;
        string state;
        solve(digits, strings, res, state, 0);
        return res;
    }

private:
    void solve(string& digits, string* strings, vector<string>& res, string& state, int i) {
        if (state.size() == digits.size()) {
            res.emplace_back(state);
            return;
        }

        for (char c : strings[digits[i] - '0']) {
            state += c;
            solve(digits, strings, res, state, i + 1);
            state.pop_back();
        }
    }
};