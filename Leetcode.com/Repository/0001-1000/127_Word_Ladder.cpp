// https://leetcode.com/problems/word-ladder/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// n = size of wordList
// m = len of each word
// time: O(n^2 * m)
// space: O(n * m)

class Solution {
public:
  int ladderLength(string& beginWord, string& endWord, vector<string>& wordList) {
    unordered_map<string, vector<string>> graph; // pattern, words
    for (const string& word : wordList) {
      string pattern = word;
      for (int i = 0; i < pattern.length(); i++) {
        pattern[i] = '*';
        graph[pattern].emplace_back(word);
        pattern[i] = word[i];
      }
    }
    
    unordered_set<string> visited;
    visited.insert(beginWord);
    
    queue<string> queue;
    queue.push(beginWord);
    
    int ladder = 1;
    while (queue.size()) {
      int size = queue.size();
      
      while (size--) {
        string word = queue.front();
        queue.pop();
        
        if (word == endWord)
          return ladder;
        
        string pattern = word;
        for (int i = 0; i < pattern.length(); i++) {
          pattern[i] = '*';
          for (const string& neighbor : graph[pattern]) {
            if (visited.count(neighbor) == 0) {
              visited.insert(neighbor);
              queue.push(neighbor);
            }
          }
          pattern[i] = word[i];
        }
      }
      ladder++;
    }
    
    return 0;
  }
};