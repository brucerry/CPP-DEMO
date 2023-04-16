// https://leetcode.com/problems/minimum-additions-to-make-valid-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int addMinimum(string word) {
        int prev = 'z', newsize = 0;
        for (char c : word) {
            newsize += (prev >= c) * 3;
            prev = c;
        }
        return newsize - word.size();
    }
};