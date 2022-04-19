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
public:
  Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> originalToCopy {
      { nullptr, nullptr }
    };
    return clone(node, originalToCopy);
  }
  
private:
  Node* clone(Node* node, unordered_map<Node*, Node*>& originalToCopy) {
    if (originalToCopy.count(node))
      return originalToCopy[node];
    
    Node* copy = new Node(node->val);
    originalToCopy[node] = copy;
    
    for (const auto& neighbor : node->neighbors) {
      copy->neighbors.emplace_back(clone(neighbor, originalToCopy));
    }
    
    return copy;
  }
};