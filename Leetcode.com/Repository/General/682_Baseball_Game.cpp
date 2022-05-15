// https://leetcode.com/problems/baseball-game/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int calPoints(vector<string>& ops) {
    vector<int> scores;
    for (const string& op : ops) {
      if (op == "+")
        scores.emplace_back(scores.back() + scores[scores.size() - 2]);
      else if (op == "D")
        scores.emplace_back(scores.back() * 2);
      else if (op == "C")
        scores.pop_back();
      else
        scores.emplace_back(stoi(op));
    }
    
    int sum = 0;
    for (const int& score : scores)
      sum += score;
    
    return sum;
  }
};