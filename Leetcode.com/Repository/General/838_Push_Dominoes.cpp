// https://leetcode.com/problems/push-dominoes/

#include <string>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)
class CalculateForce {
public:
  string pushDominoes(string dominoes) {
    int n = dominoes.length();
    vector<int> forces (n, 0);
    
    int force = 0;
    
    for (int i = 0; i < n; i++) {
      if (dominoes[i] == 'R')
        force = n;
      else if (dominoes[i] == 'L')
        force = 0;
      else
        force = max(0, force - 1);
      
      forces[i] += force;
    }
    
    force = 0;
    
    for (int i = n - 1; i >= 0; i--) {
      if (dominoes[i] == 'R')
        force = 0;
      else if (dominoes[i] == 'L')
        force = n;
      else
        force = max(0, force - 1);
      
      forces[i] -= force;
    }
    
    for (int i = 0; i < n; i++) {
      if (forces[i] > 0)
        dominoes[i] = 'R';
      else if (forces[i] < 0)
        dominoes[i] = 'L';
    }
    
    return dominoes;
  }
};

// time: O(n)
// space: O(n)
class Queue {
public:
  string pushDominoes(string dominoes) {    
    queue<pair<int, char>> queue;
    
    for (int i = 0; i < dominoes.length(); i++) {
      if (dominoes[i] != '.') {
        queue.emplace(i, dominoes[i]);
      }
    }
    
    while (queue.size()) {
      auto [ i, dir ] = queue.front();
      queue.pop();
      
      if (dir == 'L' and i > 0 and dominoes[i-1] == '.') {
        dominoes[i-1] = 'L';
        queue.emplace(i - 1, 'L');
      }
      else if (dir == 'R') {
        if (i + 1 < dominoes.length() and dominoes[i+1] == '.') {
          if (i + 2 < dominoes.length() and dominoes[i+2] == 'L') {
            queue.pop();
          }
          else {
            dominoes[i+1] = 'R';
            queue.emplace(i + 1, 'R');
          }
        }
      }
    }
    
    return dominoes;
  }
};