// https://leetcode.com/problems/alien-dictionary/

#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// n = total number of characters in words
// time: O(n)
// space: O(n)

class Solution {
public:
  string alienOrder(vector<string> &words) {
    unordered_map<char, unordered_set<char>> graph;
    for (const string& word : words) {
      for (const char& c : word) {
        graph[c] = {};
      }
    }

    for (int i = 1; i < words.size(); i++) {
      string& w1 = words[i-1];
      string& w2 = words[i];
      if (w1.length() > w2.length() and w1.find(w2) == 0)
        return "";
      for (int j = 0; j < w1.length(); j++) {
        if (w1[j] != w2[j]) {
          graph[w1[j]].emplace(w2[j]);
          break;
        }
      }
    }

    string order;
    array<char, 26> visitState { 0 }; // 0: not visited, 1: visiting, 2: visited
    for (const auto& [ node, _ ] : graph) {
      if (hasCycle(graph, node, visitState, order))
        return "";
    }

    reverse(order.begin(), order.end());

    return order;
  }

private:
  bool hasCycle(unordered_map<char, unordered_set<char>>& graph, char node, array<char, 26>& visitState, string& order) {
    if (visitState[node - 'a'] == 1)
      return true;

    if (visitState[node - 'a'] == 2)
      return false;

    visitState[node - 'a'] = 1;

    for (const char& neighbor : graph[node]) {
      if (hasCycle(graph, neighbor, visitState, order))
        return true;
    }

    order += node;
    visitState[node - 'a'] = 2;

    return false;
  }
};