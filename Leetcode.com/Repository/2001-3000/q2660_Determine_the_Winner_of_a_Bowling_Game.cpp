// https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        int score1 = 0, score2 = 0;
        for (int i = 0; i < n; i++) {
            score1 += player1[i];
            score2 += player2[i];
            if (i >= 1 and player1[i-1] == 10 or i >= 2 and player1[i-2] == 10)
                score1 += player1[i];
            if (i >= 1 and player2[i-1] == 10 or i >= 2 and player2[i-2] == 10)
                score2 += player2[i];
        }
        return score1 > score2 ? 1 : score1 < score2 ? 2 : 0;
    }
};