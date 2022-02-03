#include <string>
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



std::string bottomRightValue(Node* root) {
  queue<Node*> queue;
  queue.push(root);
  string val;
  while (queue.size()) {
    Node* currentNode = queue.front();
    queue.pop();
    val = currentNode->val;
    if (currentNode->left != nullptr) queue.push(currentNode->left);
    if (currentNode->right != nullptr) queue.push(currentNode->right);
  }
  return val;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}