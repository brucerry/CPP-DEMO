// https://leetcode.com/problems/shortest-path-to-get-all-keys/

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

// r = # rows
// c = # cols
// k = # keys
// time: O(r * c * 2^k)
// space: O(r * c * 2^k)

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<int> que;
        unordered_set<int> visited;

        int all_key = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                char ch = grid[r][c];
                if (ch == '@') {
                    que.emplace(r * 100 + c);
                    visited.emplace(r * 100 + c);
                }
                else if ('a' <= ch and ch <= 'f') {
                    all_key |= 1 << (ch - 'a');
                }
            }
        }

        int moves[] = { 0, 1, 0, -1, 0 }; // 4-dir

        int step = 0;
        while (que.size()) {
            for (int size = que.size(); size; size--) {
                int state = que.front();
                que.pop();
                int key = state / 10000, r = state / 100 % 100, c = state % 100;
                if (key == all_key)
                    return step;
                for (int i = 0; i < 4; i++) {
                    int newr = r + moves[i];
                    int newc = c + moves[i+1];
                    if (0 <= min(newr, newc) and newr < rows and newc < cols) {
                        char ch = grid[newr][newc];
                        int copy_key = key;
                        if (ch == '#')
                            continue;
                        if ('A' <= ch and ch <= 'F' and (copy_key & (1 << (ch - 'A'))) == 0)
                            continue;
                        if ('a' <= ch and ch <= 'f') 
                            copy_key |= 1 << (ch - 'a');
                        if (visited.count(copy_key * 10000 + newr * 100 + newc) == 0) {
                            visited.emplace(copy_key * 10000 + newr * 100 + newc);
                            que.emplace(copy_key * 10000 + newr * 100 + newc);
                        }
                    }
                }
            }
            step++;
        }

        return -1;
    }
};