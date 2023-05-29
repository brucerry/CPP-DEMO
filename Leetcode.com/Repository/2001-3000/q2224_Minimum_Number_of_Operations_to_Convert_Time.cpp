// https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/

#include <string>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
    int convertTime(string current, string correct) {
        int curr = mins(current);
        int corr = mins(correct);
        int diff = corr - curr;
        int res = 0;
        res += diff / 60;
        diff %= 60;
        res += diff / 15;
        diff %= 15;
        res += diff / 5;
        diff %= 5;
        res += diff;
        return res;
    }

private:
    int mins(string& time) {
        int hr = (time[0] - '0') * 10 + time[1] - '0';
        int min = (time[3] - '0') * 10 + time[4] - '0';
        return hr * 60 + min;
    }
};