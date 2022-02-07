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


// depth first
void leftyNodes(Node* root, int level, vector<string>& nodes) {
  if (root == nullptr) return;
  if (level == nodes.size()) nodes.push_back(root->val);
  
  leftyNodes(root->left, level + 1, nodes);
  leftyNodes(root->right, level + 1, nodes);
}

std::vector<std::string> leftyNodes(Node* root) {
  vector<string> nodes;
  leftyNodes(root, 0, nodes);
  return nodes;
}





// breadth first
std::vector<std::string> _leftyNodes(Node* root) {
  int prevLevel;
  vector<string> leftyNodes;
  queue<tuple<Node*, int>> queue;
  if (root != nullptr) {
    queue.push({root, 0});
    leftyNodes.push_back(root->val);
    prevLevel = 0;
  }
  
  while (queue.size()) {
    auto [ node, level ] = queue.front();
    queue.pop();
    if (level > prevLevel) {
      prevLevel = level;
      leftyNodes.push_back(node->val);
    }
    if (node->left != nullptr) queue.push({node->left, level + 1});
    if (node->right != nullptr) queue.push({node->right, level + 1});
  }
  
  return leftyNodes;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}