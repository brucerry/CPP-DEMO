// https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/

#include <vector>
#include <string>
using namespace std;

// time: O(26 * 9) -> O(1)
// space: O(1)

class Solution {
public:
    vector<string> cellsInRange(string s) {
        char r1 = s[1], c1 = s[0];
        char r2 = s[4], c2 = s[3];
        vector<string> res;
        for (char c = c1; c <= c2; c++) {
            for (char r = r1; r <= r2; r++) {
                res.push_back({ c, r });
            }
        }
        return res;
    }
};