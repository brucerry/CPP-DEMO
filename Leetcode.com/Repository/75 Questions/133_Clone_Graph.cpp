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
  Node* clone(unordered_map<Node*, Node*>& map, Node* node) {
    if (map.count(node))
      return map[node];

    Node* copy = new Node(node->val);
    map[node] = copy;

    for (Node*& neighbor : node->neighbors) {
      copy->neighbors.emplace_back(clone(map, neighbor));
    }

    return copy;
  }
  
public:
  Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> map { // originalNode, newNode
      { nullptr, nullptr }
    };
    return clone(map, node);
  }
};