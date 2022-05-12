// https://leetcode.com/problems/reconstruct-itinerary/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// time: O(e^2)
// space: O(e)

class Solution {
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    sort(tickets.begin(), tickets.end());
    
    unordered_map<string, vector<string>> graph;
    for (const auto& ticket : tickets) {
      graph[ticket[0]].emplace_back(ticket[1]);
    }
    
    vector<string> result { "JFK" };
    string src = "JFK";
    traverse(tickets.size(), graph, result, src);
    return result;
  }
  
private:
  bool traverse(int n, unordered_map<string, vector<string>>& graph, vector<string>& result, string& src) {    
    if (result.size() == n + 1) {
      return true;
    }
    
    if (graph.count(src) == 0) {
      return false;
    }
    
    int size = graph[src].size();
    for (int i = 0; i < size; i++) {
      string tmp = graph[src][i];
      
      result.emplace_back(tmp);
      graph[src].erase(graph[src].begin() + i);
      
      if (traverse(n, graph, result, tmp))
        return true;
      
      result.pop_back();
      graph[src].emplace(graph[src].begin() + i, tmp);
    }
    
    return false;
  }
};