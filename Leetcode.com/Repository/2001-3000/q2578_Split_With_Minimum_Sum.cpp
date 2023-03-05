// https://leetcode.com/problems/split-with-minimum-sum/

#include <string>
#include <algorithm>
using namespace std;

// time: O(log(num))
// space: O(log(num))

class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        
        int n = s.size(), val1 = 0, val2 = 0;
        for (int i = 0; i < n; i += 2) {
            val1 = val1 * 10 + s[i] - '0';
            if (i + 1 < n) {
                val2 = val2 * 10 + s[i+1] - '0';
            }
        }

        return val1 + val2;
    }
};