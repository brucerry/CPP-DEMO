// https://leetcode.com/problems/lexicographically-smallest-beautiful-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        for (int i = s.size() - 1; i >= 0; i--) {
            s[i]++;
            while (isInvalid(s, i)) {
                s[i]++;
            }
            if (s[i] < 'a' + k) {
                for (int j = i + 1; j < s.size(); j++) {
                    for (s[j] = 'a'; isInvalid(s, j); s[j]++);
                }
                return s;
            }
        }
        return "";
    }

private:
    bool isInvalid(string& s, int i) {
        return (i >= 1 and s[i-1] == s[i]) or (i >= 2 and s[i-2] == s[i]);
    }
};