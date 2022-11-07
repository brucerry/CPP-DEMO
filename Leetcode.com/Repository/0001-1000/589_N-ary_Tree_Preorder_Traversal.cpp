// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

#include <vector>
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

class Recursive {
public:
  vector<int> preorder(Node* root) {
    vector<int> result;
    solve(root, result);
    return result;
  }

private:
  void solve(Node* node, vector<int>& result) {
    if (!node)
      return;
    result.emplace_back(node->val);
    for (const auto& child : node->children)
      solve(child, result);
  }
};

class Iterative {
public:
  vector<int> preorder(Node* root) {
    vector<int> result;
    vector<Node*> stack;
    if (root)
      stack.emplace_back(root);
    while (stack.size()) {
      Node* node = stack.back();
      stack.pop_back();
      result.emplace_back(node->val);
      for (auto it = node->children.rbegin(); it != node->children.rend(); it++) {
        stack.emplace_back(*it);
      }
    }
    return result;
  }
};