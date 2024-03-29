// https://leetcode.com/problems/satisfiability-of-equality-equations/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool equationsPossible(vector<string>& equations) {
    int parents[26];
    for (int i = 0; i < 26; i++)
      parents[i] = i;
    
    for (const string& equ : equations) {
      if (equ[1] == '=')
        parents[findParent(parents, equ[0] - 'a')] = findParent(parents, equ[3] - 'a');
    }
    
    for (const string& equ : equations) {
      if (equ[1] == '!' and findParent(parents, equ[0] - 'a') == findParent(parents, equ[3] - 'a'))
        return false;
    }
    
    return true;
  }
  
private:
  int findParent(int* parents, char node) {
    while (node != parents[node]) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }
};