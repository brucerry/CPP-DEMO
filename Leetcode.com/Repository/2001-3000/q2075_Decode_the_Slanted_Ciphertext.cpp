// https://leetcode.com/problems/decode-the-slanted-ciphertext/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        int r = 0, c = 0, start_c = 0;
        string res;
        while (c < cols) {
            int _1d_index = r * cols + c;
            res += encodedText[_1d_index];
            r = (r + 1) % rows;
            if (r == 0) {
                start_c++;
                c = start_c;
            }
            else
                c++;
        }
        while (res.back() == ' ')
            res.pop_back();
        return res;
    }
};