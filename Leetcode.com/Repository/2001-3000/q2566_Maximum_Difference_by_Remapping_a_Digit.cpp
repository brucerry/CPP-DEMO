// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/

#include <string>
using namespace std;

// time: O(log(num))
// space: O(log(num))

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num), maxnum = s, minnum = s;
        char maxhead = s[0] == '9' ? -1 : s[0];
        char minhead = s[0];
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == minhead)
                minnum[i] = '0';
            if (s[i] == maxhead or (maxhead == -1 and s[i] != '9')) {
                maxhead = s[i];
                maxnum[i] = '9';
            }
        }
        return stoi(maxnum) - stoi(minnum);
    }
};