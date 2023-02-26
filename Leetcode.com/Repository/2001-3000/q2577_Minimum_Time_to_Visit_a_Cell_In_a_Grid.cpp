// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/

#include <vector>
#include <queue>
using namespace std;

// time: O(r * c * log(r * c))
// space: O(r * c)

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (min(grid[0][1], grid[1][0]) > 1)
            return -1;

        int moves[] { 0, 1, 0, -1, 0 }; // 4-dir

        vector<vector<int>> visited (rows, vector<int>(cols));
        visited[0][0] = 1;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minheap; // time, r, c
        minheap.push({ 0, 0, 0 });
        
        while (minheap.size()) {
            int time = minheap.top()[0], r = minheap.top()[1], c = minheap.top()[2];
            minheap.pop();
            if (r == rows - 1 and c == cols - 1)
                return time;
            for (int i = 0; i < 4; i++) {
                int newr = r + moves[i];
                int newc = c + moves[i+1];
                if (min(newr, newc) >= 0 and newr < rows and newc < cols and visited[newr][newc] == 0) {
                    visited[newr][newc] = 1;
                    int wait = (grid[newr][newc] - time) % 2 == 0;
                    minheap.push({ max(time + 1, grid[newr][newc] + wait), newr, newc });
                }
            }
        }
        
        return -1;
    }
};