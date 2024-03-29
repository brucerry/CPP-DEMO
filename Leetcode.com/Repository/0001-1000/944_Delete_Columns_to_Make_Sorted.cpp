// https://leetcode.com/problems/delete-columns-to-make-sorted/

#include <vector>
#include <string>
using namespace std;

// n = size of strs
// m = len of strs[i]
// time: O(n * m)
// space: O(1)

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int res = 0;
        for (int c = 0; c < cols; c++) {
            char prev = -1, isSorted = true;
            for (int r = 0; r < rows; r++) {
                isSorted = isSorted and strs[r][c] >= prev;
                prev = strs[r][c];
            }
            res += !isSorted;
        }
        return res;
    }
};