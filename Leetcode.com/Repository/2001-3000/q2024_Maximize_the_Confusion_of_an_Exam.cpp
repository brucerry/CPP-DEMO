// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int count[2] {};
        int res = 0, max_count = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            max_count = max(max_count, ++count[s[r] == 'T']);
            while (r - l + 1 - max_count > k) {
                count[s[l++] == 'T']--;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};