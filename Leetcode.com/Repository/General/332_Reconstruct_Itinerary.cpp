// https://leetcode.com/problems/reconstruct-itinerary/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// time: O((n + e)^2) => O(e^2), where ^2 comes from backtracking
// space: O(e)

class Solution {
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    sort(tickets.begin(), tickets.end());
    
    unordered_map<string, vector<string>> graph; // node, neighbors
    for (const auto& ticket : tickets) {
      const string& from = ticket[0];
      const string& to = ticket[1];
      graph[from].emplace_back(to);
    }
    
    vector<string> result { "JFK" };
    string node = "JFK";
    solve(tickets.size(), graph, result, node);
    return result;
  }
  
private:
  bool solve(int n, unordered_map<string, vector<string>>& graph, vector<string>& result, string& node) {
    if (result.size() == n + 1)
      return true;
    
    if (graph.count(node) == 0)
      return false;
    
    int size = graph[node].size();
    for (int i = 0; i < size; i++) {
      string neighbor = graph[node][i];
      
      result.emplace_back(neighbor);
      graph[node].erase(graph[node].begin() + i);
      
      if (solve(n, graph, result, neighbor))
        return true;
      
      graph[node].emplace(graph[node].begin() + i, neighbor);
      result.pop_back();
    }
    
    return false;
  }
};