// https://leetcode.com/problems/number-of-senior-citizens/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (string& det : details) {
            int age = (det[11] - '0') * 10 + (det[12] - '0');
            res += age > 60;
        }
        return res;
    }
};