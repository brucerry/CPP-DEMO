// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    bool winnerOfGame(string s) {
        int a = 0, b = 0;
        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i-1] == s[i] and s[i] == s[i+1]) {
                a += s[i] == 'A';
                b += s[i] == 'B';
            }
        }
        return a > b;
    }
};