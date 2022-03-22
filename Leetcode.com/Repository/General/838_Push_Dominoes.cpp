// https://leetcode.com/problems/push-dominoes/

#include <string>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  string pushDominoes(string& dominoes) {
    queue<pair<char, int>> queue;

    for (int i = 0; i < dominoes.length(); i++) {
      if (dominoes[i] != '.') queue.push({dominoes[i], i});
    }

    while (queue.size()) {
      auto [ ch, i ] = queue.front();
      queue.pop();

      if (ch == 'L' && i > 0 && dominoes[i-1] == '.') {
        dominoes[i-1] = 'L';
        queue.push({'L', i-1});
      }
      else if (ch == 'R') {
        if (i + 1 < dominoes.length() && dominoes[i+1] == '.') {
          if (i + 2 < dominoes.length() && dominoes[i+2] == 'L') {
            queue.pop();
          }
          else {
            dominoes[i+1] = 'R';
            queue.push({'R', i+1});
          }
        }
      }
    }

    return dominoes;
  }
};