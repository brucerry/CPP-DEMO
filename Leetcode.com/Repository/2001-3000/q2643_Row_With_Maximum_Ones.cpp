// https://leetcode.com/problems/row-with-maximum-ones/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int maxindex = 0, maxcount = 0;
        for (int r = 0; r < rows; r++) {
            int count = 0;
            for (int c = 0; c < cols; c++) {
                count += mat[r][c] == 1;
            }
            if (maxcount < count) {
                maxcount = count;
                maxindex = r;
            }
        }
        
        return { maxindex, maxcount };
    }
};