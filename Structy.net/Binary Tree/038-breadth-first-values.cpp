#include <string>
#include <vector>
#include <queue>
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



std::vector<std::string> breadthFirstValues(Node* root) {
  vector<string> values;
  queue<Node*> queue;
  if (root != nullptr) queue.push(root);
  while (queue.size()) {
    Node* node = queue.front();
    queue.pop();
    values.push_back(node->val);
    if (node->left != nullptr) queue.push(node->left);
    if (node->right != nullptr) queue.push(node->right);
  }
  return values;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}