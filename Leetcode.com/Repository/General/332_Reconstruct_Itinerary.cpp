// https://leetcode.com/problems/reconstruct-itinerary/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// time: O((n + e)^2)
// space: O(n + e)

class Solution {
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    int n = tickets.size();
    
    sort(tickets.begin(), tickets.end());
    
    unordered_map<string, vector<string>> graph; // node, neighbors
    for (const auto& ticket : tickets) {
      const string& from = ticket[0];
      const string& to = ticket[1];
      graph[from].emplace_back(to);
    }
    
    vector<string> result { "JFK" };
    string src = "JFK";
    solve(n, graph, result, src);
    return result;
  }
  
private:
  bool solve(int n, unordered_map<string, vector<string>>& graph, vector<string>& result, string& src) {
    if (result.size() == n + 1)
      return true;
    
    if (graph.count(src) == 0)
      return false;
    
    int size = graph[src].size();
    for (int i = 0; i < size; i++) {
      string neighbor = graph[src][i];
      
      result.emplace_back(neighbor);
      graph[src].erase(graph[src].begin() + i);
      
      if (solve(n, graph, result, neighbor))
        return true;
      
      graph[src].emplace(graph[src].begin() + i, neighbor);
      result.pop_back();
    }
    
    return false;
  }
};