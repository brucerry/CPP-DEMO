// https://leetcode.com/problems/string-compression/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        chars.emplace_back('\0');
        int count = 1, j = 0, prevchar = chars[0];
        for (int i = 1; i < chars.size(); i++) {
            if (prevchar == chars[i]) {
                count++;
            }
            else {
                chars[j++] = prevchar;
                if (count > 1) {
                    int j_copy = j;
                    while (count) {
                        chars[j++] = count % 10 + '0';
                        count /= 10;
                    }
                    reverse(chars.begin() + j_copy, chars.begin() + j);
                }
                prevchar = chars[i];
                count = 1;
            }
        }
        return j;
    }
};