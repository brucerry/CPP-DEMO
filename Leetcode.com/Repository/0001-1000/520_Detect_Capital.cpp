// https://leetcode.com/problems/detect-capital/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allUpper = true, allLower = true, onlyFirstUpper = true;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            allUpper = allUpper and isupper(c);
            allLower = allLower and islower(c);
            onlyFirstUpper = onlyFirstUpper and (i == 0 ? isupper(c) : islower(c));
        }
        return allUpper or allLower or onlyFirstUpper;
    }
};