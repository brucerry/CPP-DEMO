// https://leetcode.com/problems/alien-dictionary/

// https://www.youtube.com/watch?v=6kTZYvNNyps

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
  int differentIndex(string s1, string s2) {
    int i = 0;
    while (i < s1.length()) {
      if (s1[i] != s2[i]) return i;
      i++;
    }
    return -1; // error
  }

public:
  string alienOrder(vector<string> words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_set<char> allAlphabet;
    for (auto word : words) {
      for (auto ch : word) {
        allAlphabet.insert(ch);
        if (graph.count(ch) == 0) graph[ch] = {};
      }
    }

    for (int i = 0; i < words.size(); i++) {
      for (int j = i + 1; j < words.size(); j++) {
        if (words[j].find(words[i]) != string::npos) continue;
        int idx = differentIndex(words[i], words[j]);
        graph[words[i][idx]].insert(words[j][idx]);
      }
    }

    // print
    // for (auto [ node, neighbors ] : graph) {
    //   cout << node << ": ";
    //   for (auto neighbor : neighbors) {
    //     cout << neighbor << " ";
    //   }
    //   cout << endl;
    // }
    // print

    unordered_map<char, int> numParents;
    for (auto [ node, neighbors ] : graph) {
      if (numParents.count(node) == 0) numParents[node] = 0;
      for (auto neighbor : neighbors) {
        numParents[neighbor]++;
      }
    }

    vector<char> ready;
    for (auto [ node, count ] : numParents) {
      if (count == 0) ready.push_back(node);
    }

    string result;
    unordered_set<char> visited;
    while (ready.size()) {
      char node = ready.back();
      if (visited.count(node)) return "";
      visited.insert(node);
      result += node;
      ready.pop_back();

      for (auto neighbor : graph[node]) {
        if (--numParents[neighbor] == 0) {
          ready.push_back(neighbor);
        }
      }
    }

    return visited.size() == allAlphabet.size() ? result : "";
  }
};

int main() {
  Solution sol;
  cout << sol.alienOrder({"wrt", "wrf", "er", "ett", "rftt"}) << endl; // "wertf"
  cout << sol.alienOrder({"z", "x"}) << endl; // "zx"
  cout << sol.alienOrder({"zy", "zx"}) << endl; // "yxz"
  cout << sol.alienOrder({"a", "b", "c", "a"}) << endl; // ""
  cout << sol.alienOrder({"ab", "bc", "cd", "a"}) << endl; // ""
}