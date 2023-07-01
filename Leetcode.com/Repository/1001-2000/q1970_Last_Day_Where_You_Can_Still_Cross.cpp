// https://leetcode.com/problems/last-day-where-you-can-still-cross/

#include <vector>
#include <queue>
using namespace std;

// time: O(r * c * log(r * c))
// space: O(r * c)

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0, r = cells.size() - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (bfs(row, col, cells, m))
                l = m;
            else
                r = m - 1;
        }
        return l + 1;
    }

private:
    bool bfs(int row, int col, vector<vector<int>>& cells, int m) {
        int moves[] = { 0, 1, 0, -1, 0 };

        vector<vector<int>> visited (row, vector<int>(col));
        for (int i = 0; i <= m; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            visited[r][c] = 1;
        }

        queue<pair<int, int>> que; // r, c
        for (int c = 0; c < col; c++) {
            if (visited[0][c] == 0)
                que.emplace(0, c);
        }

        while (que.size()) {
            for (int size = que.size(); size; size--) {
                auto [ r, c ] = que.front();
                que.pop();
                if (r == row - 1)
                    return true;
                for (int i = 0; i < 4; i++) {
                    int newr = r + moves[i];
                    int newc = c + moves[i+1];
                    if (0 <= min(newr, newc) and newr < row and newc < col and visited[newr][newc] == 0) {
                        visited[newr][newc] = 1;
                        que.emplace(newr, newc);
                    }
                }
            }
        }

        return false;
    }
};