// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

#include <vector>
#include <string>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int row_A[3] {}, col_A[3] {}, diag_A[2] {};
        int row_B[3] {}, col_B[3] {}, diag_B[2] {};

        for (int i = 0; i < moves.size(); i++) {
            int r = moves[i][0];
            int c = moves[i][1];
            if (i % 2)
                row_B[r]++, col_B[c]++, diag_B[0] += (r + c == 2), diag_B[1] += (r - c == 0);
            else
                row_A[r]++, col_A[c]++, diag_A[0] += (r + c == 2), diag_A[1] += (r - c == 0);
        }
        for (int i = 0; i < 3; i++) {
            if (max({ row_A[i], col_A[i], diag_A[0], diag_A[1] }) == 3)
                return "A";
            if (max({ row_B[i], col_B[i], diag_B[0], diag_B[1] }) == 3)
                return "B";
        }
        return moves.size() < 9 ? "Pending" : "Draw";
    }
};