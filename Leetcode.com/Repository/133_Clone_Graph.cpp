// https://leetcode.com/problems/clone-graph/

#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
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

class Solution {
private:
  void makeGraph(unordered_map<Node*, vector<Node*>> &graph, Node* node) {
    if (graph.count(node)) return;
    if (graph.count(node) == 0) graph[node] = {};
    for (auto neighbor : node->neighbors) {
      graph[node].push_back(neighbor);
      makeGraph(graph, neighbor);
    }
  }

public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;

    unordered_map<Node*, vector<Node*>> graph;
    makeGraph(graph, node);

    Node* newNodes[graph.size()];
    for (auto pair : graph) {
      newNodes[pair.first->val - 1] = new Node(pair.first->val);
    }

    for (auto [ node, neighbors ] : graph) {
      for (auto neighbor : neighbors) {
        newNodes[node->val - 1]->neighbors.push_back(newNodes[neighbor->val - 1]);
      }
    }

    return newNodes[0];
  }
};