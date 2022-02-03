#include <string>
#include <stack>
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
bool treeIncludes(Node* root, std::string targetVal) {
  if (root == nullptr) return false;
  if (root->val == targetVal) return true;
  return treeIncludes(root->left, targetVal) || treeIncludes(root->right, targetVal);
}





// iterative
bool _treeIncludes(Node* root, std::string targetVal) {
  stack<Node*> stack;
  if (root != nullptr) stack.push(root);
  while (stack.size()) {
    Node* currentNode = stack.top();
    stack.pop();
    if (currentNode->val == targetVal) return true;
    if (currentNode->left != nullptr) stack.push(currentNode->left);
    if (currentNode->right != nullptr) stack.push(currentNode->right);
  }
  return false;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}