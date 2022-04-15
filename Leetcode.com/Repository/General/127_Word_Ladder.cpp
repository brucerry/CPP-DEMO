// https://leetcode.com/problems/word-ladder/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// n = len of wordList (# of nodes)
// m = len of each word
// time: O(n * m^2)
// space: O(n * m)

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {    
    wordList.emplace_back(beginWord);
    
    unordered_map<string, vector<string>> patternMap; // pattern, words
    
    for (const string& word : wordList) {
      for (int i = 0; i < word.length(); i++) {
        string pattern = word;
        pattern[i] = '*';
        patternMap[pattern].emplace_back(word);
      }
    }
    
    unordered_set<string> visited { beginWord };
    
    queue<string> queue;
    queue.emplace(beginWord);
    int ans = 1;
    
    while (queue.size()) {
      int len = queue.size();
      
      while (len--) {
        string word = queue.front();
        queue.pop();
        
        if (word == endWord)
          return ans;
        
        for (int i = 0; i < word.length(); i++) {
          string pattern = word;
          pattern[i] = '*';
          for (const string& neighbor : patternMap[pattern]) {
            if (visited.count(neighbor) == 0) {
              visited.emplace(neighbor);
              queue.emplace(neighbor);
            }
          }
        }
      }
      
      ans++;
    }
    
    return 0;
  }
};