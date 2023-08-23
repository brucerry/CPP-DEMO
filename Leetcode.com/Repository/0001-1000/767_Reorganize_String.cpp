// https://leetcode.com/problems/reorganize-string/

#include <string>
#include <array>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        int count[26] {}, max_count = 0, max_ch = 0;
        for (char c : s) {
            if (max_count < ++count[c - 'a']) {
                max_count = count[c - 'a'];
                max_ch = c;
            }
        }

        if (max_count > (n + 1) / 2)
            return "";

        string res (n, '.');
        int i = 0;
        while (count[max_ch - 'a']) {
            res[i] = max_ch;
            count[max_ch - 'a']--;
            i += 2;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            while (count[c - 'a']) {
                if (i >= n)
                    i = 1;
                res[i] = c;
                i += 2;
                count[c - 'a']--;
            }
        }

        return res;
    }
};