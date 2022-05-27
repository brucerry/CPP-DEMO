// https://leetcode.com/problems/word-break-ii/

#include <vector>
#include <string>
using namespace std;

// s = len of s
// n = len of wordDict
// time: O(n^s)
// space: O(s)

class Solution {
public:
  vector<string> wordBreak(string& s, vector<string>& wordDict) {
    vector<string> solution;
    vector<string> state;
    solve(s, wordDict, solution, state, 0);
    return solution;
  }
  
private:
  void solve(string& s, vector<string>& wordDict, vector<string>& solution, vector<string>& state, int i) {
    if (i == s.length()) {
      addSolution(solution, state);
      return;
    }
    
    for (const string& word : wordDict) {
      if (i == s.find(word, i)) {
        state.emplace_back(word);
        solve(s, wordDict, solution, state, i + word.length());
        state.pop_back();
      }
    }
  }
  
  void addSolution(vector<string>& solution, vector<string>& state) {
    string sentence;
    for (int i = 0; i < state.size(); i++) {
      sentence += i ? ' ' + state[i] : state[i];
    }
    solution.emplace_back(sentence);
  }
};