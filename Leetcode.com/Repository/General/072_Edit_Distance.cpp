// https://leetcode.com/problems/edit-distance/

#include <string>
#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int minDistance(string& word1, string& word2) {
    vector<vector<int>> memo (word1.length() + 1, vector<int>(word2.length() + 1, INT_MAX));

    for (int r = 0; r <= word1.length(); r++) {
      memo[r][word2.length()] = word1.length() - r;
    }

    for (int c = 0; c <= word2.length(); c++) {
      memo[word1.length()][c] = word2.length() - c;
    }

    for (int r = word1.length() - 1; r >= 0; r--) {
      for (int c = word2.length() - 1; c >= 0; c--) {
        if (word1[r] == word2[c]) {
          memo[r][c] = memo[r+1][c+1];
        } else {
          memo[r][c] = 1 + min({memo[r+1][c+1], memo[r+1][c], memo[r][c+1]});
        }
      }
    }

    return memo[0][0];
  }
};

// class Solution {
// private:
//   int minDistance(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
//     if (i == word1.length() && j == word2.length()) return 0;
//     else if (i == word1.length()) return word2.length() - j;
//     else if (j == word2.length()) return word1.length() - i;
//     if (memo[i][j] != -1) return memo[i][j];

//     if (word1[i] == word2[j]) {
//       return memo[i][j] = minDistance(word1, word2, i+1, j+1, memo);
//     } else {
//       return memo[i][j] = 1 + min({minDistance(word1, word2, i, j+1, memo), minDistance(word1, word2, i+1, j, memo), minDistance(word1, word2, i+1, j+1, memo)});
//     }
//   }

// public:
//   int minDistance(string& word1, string& word2) {
//     if (word1.length() == 0 || word2.length() == 0) return max(word1.length(), word2.length());
//     if (word1 == word2) return 0;

//     vector<vector<int>> memo (word1.length(), vector<int>(word2.length(), -1));

//     return minDistance(word1, word2, 0, 0, memo);
//   }
// };