#include <vector>
#include <string>
#include <queue>
#include <tuple>
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


// recursive
void treeLevels(Node* root, int level, vector<vector<string>> &levels) {
  if (root == nullptr) return;
  
  if (level < levels.size()) {
    levels[level].push_back(root->val);
  } else {
    levels.push_back({root->val});
  }
  
  treeLevels(root->left, level+1, levels);
  treeLevels(root->right, level+1, levels);
}


std::vector<std::vector<std::string>> treeLevels(Node* root) {
  vector<vector<string>> levels;
  treeLevels(root, 0, levels);
  return levels;
}




// iterative
std::vector<std::vector<std::string>> _treeLevels(Node* root) {
  vector<vector<string>> levels;
  queue<tuple<Node*, int>> queue;
  if (root != nullptr) queue.push({root, 0});
  while (queue.size()) {
    auto [ node, level ] = queue.front();
    queue.pop();
    if (level < levels.size()) {
      levels[level].push_back(node->val);
    } else {
      levels.push_back({node->val});
    }
    if (node->left != nullptr) queue.push({node->left, level+1});
    if (node->right != nullptr) queue.push({node->right, level+1});
  }
  return levels;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}