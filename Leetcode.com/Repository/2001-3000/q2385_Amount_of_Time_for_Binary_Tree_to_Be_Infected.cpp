// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// n = # of nodes
// e = # of edges of a full binary tree (worst case) = n - 1
// time: O(n)
// space: O(n)

class Solution {
public:
  int amountOfTime(TreeNode* root, int start) {
    unordered_map<int, vector<int>> graph;
    buildGraph(root, graph);
    
    queue<int> queue;
    queue.emplace(start);
    
    unordered_map<int, bool> visited;
    visited[start] = true;
    
    int mins = -1;
    while (queue.size()) {
      for (int size = queue.size(); size; size--) {
        int node = queue.front();
        queue.pop();
        
        for (const int& neighbor : graph[node]) {
          if (!visited[neighbor]) {
            visited[neighbor] = true;
            queue.emplace(neighbor);
          }
        }
      }
      mins++;
    }
    
    return mins;
  }
  
private:
  void buildGraph(TreeNode* node, unordered_map<int, vector<int>>& graph) {
    if (!node)
      return;
    
    if (node->left) {
      graph[node->val].emplace_back(node->left->val);
      graph[node->left->val].emplace_back(node->val);
    }
    
    if (node->right) {
      graph[node->val].emplace_back(node->right->val);
      graph[node->right->val].emplace_back(node->val);
    }
    
    buildGraph(node->left, graph);
    buildGraph(node->right, graph);
  }
};