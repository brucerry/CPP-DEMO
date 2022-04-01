// https://leetcode.com/problems/clone-graph/

#include <vector>
#include <unordered_map>
using namespace std;


class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// time: O(n + e)
// space: O(n)

class Solution {
private:
  void buildGraph(unordered_map<Node*, vector<Node*>>& graph, Node* node) {
    if (!node || graph.count(node)) return;
    if (graph.count(node) == 0) graph[node] = {};
    
    for (Node*& neighbor : node->neighbors) {
      graph[node].emplace_back(neighbor);
      buildGraph(graph, neighbor);
    }
  }
  
public:
  Node* cloneGraph(Node* node) {
    if (!node) return node;
    
    unordered_map<Node*, vector<Node*>> graph;
    buildGraph(graph, node);
    
    vector<Node*> newNodes (graph.size());
    
    for (auto& pair : graph) {
      newNodes[pair.first->val - 1] = new Node(pair.first->val);
    }
    
    for (auto& [ node, neighbors ] : graph) {
      for (Node*& neighbor : neighbors) {
        newNodes[node->val - 1]->neighbors.emplace_back(newNodes[neighbor->val - 1]);
      }
    }
    
    return newNodes[0];
  }
};