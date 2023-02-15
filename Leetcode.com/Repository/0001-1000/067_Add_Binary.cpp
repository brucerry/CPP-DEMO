// https://leetcode.com/problems/add-binary/

#include <string>
using namespace std;

// time: O(max(a, b))
// space: O(1)

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res;
        
        while (i >= 0 or j >= 0 or carry) {
            int ai = i >= 0 ? a[i] - '0' : 0;
            int bj = j >= 0 ? b[j] - '0' : 0;
            int sum = ai + bj + carry;
            carry = sum >> 1;
            res.append(1, char((sum & 1) + '0'));
            i--, j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};