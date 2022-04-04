// https://leetcode.com/problems/alien-dictionary/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// n = total number of characters in words
// time: O(n)
// space: O(n)

class Solution {
private:
  bool hasCycle(unordered_map<char, unordered_set<char>> &graph, const char& node, string& result, vector<char>& visitStates) {
    if (visitStates[node - 'a'] == 1) return true;
    if (visitStates[node - 'a'] == 2) return false;

    visitStates[node - 'a'] = 1;

    for (const char& neighbor : graph[node]) {
      if (hasCycle(graph, neighbor, result, visitStates)) return true;
    }

    visitStates[node - 'a'] = 2;

    result += node;

    return false;
  }

public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;

    for (const string& word : words) {
      for (const char& ch : word) {
        graph[ch] = {};
      }
    }

    for (int i = 0; i < words.size() - 1; i++) {
      string_view word1 = words[i];
      string_view word2 = words[i + 1];
      int minLen = min(word1.length(), word2.length());

      if (word1.substr(0, minLen) == word2.substr(0, minLen) && word1.length() > word2.length()) return "";

      for (int j = 0; j < minLen; j++) {
        if (word1[j] != word2[j]) {
          graph[word1[j]].emplace(word2[j]);
          break;
        }
      }
    }

    vector<char> visitStates (26, 0); // 1: visiting, 2: visited
    string result;

    for (const auto& [ node, _ ] : graph) {
      if (hasCycle(graph, node, result, visitStates)) return "";
    }

    reverse(result.begin(), result.end());
    return result;
  }
};