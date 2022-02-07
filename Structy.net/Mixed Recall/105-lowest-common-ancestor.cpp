#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Node {
  public:
    std::string val;
    Node* left;
    Node* right;


    Node(std::string initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};


vector<string> dfs(Node* root, string val) {
  if (root == nullptr) return {};
  if (root->val == val) return {val};
  
  vector<string> left = dfs(root->left, val);
  if (left.size()) {
    left.push_back(root->val);
    return left;
  }
  
  vector<string> right = dfs(root->right, val);
  if (right.size()) {
    right.push_back(root->val);
    return right;
  }
  
  return {};
}

std::string lowestCommonAncestor(Node* root, std::string val1, std::string val2) {
  vector<string> path1 = dfs(root, val1);
  vector<string> path2 = dfs(root, val2);
  unordered_set<string> set1 (path1.begin(), path1.end());
  
  for (auto val2 : path2) {
    if (set1.count(val2)) return val2;
  }
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}