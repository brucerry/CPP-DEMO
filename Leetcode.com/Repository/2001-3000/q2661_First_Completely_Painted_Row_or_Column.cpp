// https://leetcode.com/problems/first-completely-painted-row-or-column/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(r * c)
// space: O(r + c)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        unordered_map<int, pair<int, int>> umap;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int num = mat[r][c];
                umap[num] = { r, c };
            }
        }
        
        vector<int> rowcount (rows);
        vector<int> colcount (cols);
        
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            auto [ r, c ] = umap[num];
            rowcount[r]++;
            colcount[c]++;
            if (rowcount[r] == cols or colcount[c] == rows)
                return i;
        }
        
        return arr.size() - 1;
    }
};