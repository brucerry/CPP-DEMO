// https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    string smallestString(string s) {
        int n = s.size(), i = 0;

        while (i < n and s[i] == 'a')
            i++;

        if (i == n) {
            s.back() = 'z';
        }

        for (; i < n; i++) {
            if (s[i] == 'a')
                break;
            s[i]--;
        }
        
        return s;
    }
};