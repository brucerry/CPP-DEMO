// https://leetcode.com/problems/alien-dictionary/

// https://www.youtube.com/watch?v=6kTZYvNNyps

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// n = total number of characters in words
// time: O(n)
// space: O(n)

class Solution {
private:
  bool hasCycle(unordered_map<char, unordered_set<char>> &graph, const char& node, string& result, unordered_set<char>& visiting, unordered_set<char>& visited) {
    if (visiting.count(node)) return true;
    if (visited.count(node)) return false;

    visiting.insert(node);

    for (auto& neighbors : graph[node]) {
      if (hasCycle(graph, neighbors, result, visiting, visited)) return true;
    }

    visiting.erase(node);
    visited.insert(node);

    result += node;

    return false;
  }

public:
  string alienOrder(vector<string> words) {
    unordered_map<char, unordered_set<char>> graph;

    for (string& word : words) {
      for (char& ch : word) {
        graph[ch] = {};
      }
    }

    for (int i = 0; i < words.size() - 1; i++) {
      string& word1 = words[i];
      string& word2 = words[i + 1];
      int minLen = min(word1.length(), word2.length());

      if (word1.length() > word2.length() && word1.substr(0, minLen) == word2.substr(0, minLen)) return "";

      for (int j = 0; j < minLen; j++) {
        if (word1[j] != word2[j]) {
          graph[word1[j]].insert(word2[j]);
          break;
        }
      }
    }

    unordered_set<char> visiting;
    unordered_set<char> visited;
    string result;

    for (auto& pair : graph) {
      if (hasCycle(graph, pair.first, result, visiting, visited)) return "";
    }

    reverse(result.begin(), result.end());
    return result;
  }
};