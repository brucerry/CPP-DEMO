// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include <vector>
#include <queue>
using namespace std;

class Node {
public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) {
      val = _val;
  }

  Node(int _val, vector<Node*> _children) {
      val = _val;
      children = _children;
  }
};

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    queue<Node*> queue;
    if (root)
      queue.emplace(root);
    
    vector<vector<int>> result;
    while (queue.size()) {
      int size = queue.size();
      vector<int> level;
      
      while (size--) {
        Node* node = queue.front();
        queue.pop();
        
        level.emplace_back(node->val);
        
        for (const auto& child : node->children) {
          queue.emplace(child);
        }
      }
      
      result.emplace_back(level);
    }
    
    return result;
  }
};