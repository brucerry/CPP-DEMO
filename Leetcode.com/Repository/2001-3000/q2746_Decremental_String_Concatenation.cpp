// https://leetcode.com/problems/decremental-string-concatenation/

#include <vector>
#include <string>
using namespace std;

// time: O(n * 26 * 26)
// space: O(n * 26 * 26)

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int memo[1000][26][26] {};
        return words[0].size() + solve(words, memo, 1, words[0].front() - 'a', words[0].back() - 'a');
    }

private:
    int solve(vector<string>& words, int (*memo)[26][26], int i, char first, char last) {
        if (i == words.size())
            return 0;
        
        int& res = memo[i][first][last];
        if (res)
            return res;

        res = INT_MAX;
        res = min(res, (int)words[i].size() - (first == words[i].back() - 'a') + solve(words, memo, i + 1, words[i].front() - 'a', last));
        res = min(res, (int)words[i].size() - (last == words[i].front() - 'a') + solve(words, memo, i + 1, first, words[i].back() - 'a'));

        return res;
    }
};