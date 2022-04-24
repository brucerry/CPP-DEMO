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
    
    for (string& word : wordList) {
      string copy = word;
      
      for (char& ch : word) {
        char tmp_ch = ch;
        ch = '*';
        patternMap[word].emplace_back(copy);
        ch = tmp_ch;
      }
    }
    
    unordered_set<string> visited { beginWord };
    
    queue<string> queue;
    queue.emplace(beginWord);

    int ans = 1;
    
    while (queue.size()) {
      int len = queue.size();
      
      while (len--) {
        string& word = queue.front();
        
        if (word == endWord)
          return ans;
        
        for (char& ch : word) {
          char tmp_ch = ch;
          ch = '*';
          for (const string& neighbor : patternMap[word]) {
            if (visited.count(neighbor) == 0) {
              visited.emplace(neighbor);
              queue.emplace(neighbor);
            }
          }
          ch = tmp_ch;
        }

        queue.pop();
      }
      
      ans++;
    }
    
    return 0;
  }
};