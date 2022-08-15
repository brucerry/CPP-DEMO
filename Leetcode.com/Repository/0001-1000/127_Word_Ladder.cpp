// https://leetcode.com/problems/word-ladder/

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

// n = size of wordList
// m = len of each word
// time: O(n * m)
// space: O(n * m)

class BidirectionalBFS {
public:
  int ladderLength(string& beginWord, string& endWord, vector<string>& wordList) {
    unordered_set<string> wordSet (wordList.begin(), wordList.end());
    unordered_set<string> head { beginWord }, tail { endWord }, *phead, *ptail, tmp;
    
    if (wordSet.count(endWord) == 0)
      return 0;
    
    int ladder = 2;
    while (head.size() and tail.size()) {
      if (head.size() < tail.size()) {
        phead = &head;
        ptail = &tail;
      }
      else {
        phead = &tail;
        ptail = &head;
      }
      
      tmp = {};
      for (auto it = phead->begin(); it != phead->end(); it++) {
        string word = *it;
        for (int i = 0; i < word.length(); i++) {
          char c = word[i];
          for (char j = 'a'; j <= 'z'; j++) {
            word[i] = j;
            if (ptail->count(word))
              return ladder;
            if (wordSet.count(word)) {
              tmp.emplace(word);
              wordSet.erase(word);
            }
          }
          word[i] = c;
        }
      }
      
      ladder++;
      *phead = tmp;
    }
    
    return 0;
  }
};

class BFS {
public:
  int ladderLength(string& beginWord, string& endWord, vector<string>& wordList) {
    unordered_set<string> wordSet (wordList.begin(), wordList.end());
    if (wordSet.count(endWord) == 0)
      return 0;
    
    queue<string> queue;
    queue.emplace(beginWord);
    
    int ladder = 1;
    while (queue.size()) {
      int size = queue.size();
      
      while (size--) {
        string word = queue.front();
        queue.pop();
        
        if (word == endWord)
          return ladder;
        
        for (int i = 0; i < word.length(); i++) {
          char c = word[i];
          for (char j = 'a'; j <= 'z'; j++) {
            word[i] = j;
            if (wordSet.count(word)) {
              queue.emplace(word);
              wordSet.erase(word);
            }
          }
          word[i] = c;
        }
      }
      ladder++;
    }
    
    return 0;
  }
};