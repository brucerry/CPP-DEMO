#include <string>
#include <vector>
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
void depthFirstValues(Node* root, vector<string> &values) {
  if (root == nullptr) return;
  
  values.push_back(root->val);
  depthFirstValues(root->left, values);
  depthFirstValues(root->right, values);
}

std::vector<std::string> depthFirstValues(Node* root) {
  vector<string> values;
  depthFirstValues(root, values);
  return values;
}



// iterative
std::vector<std::string> _depthFirstValues(Node* root) {
  vector<string> values;
  stack<Node*> stack;
  if (root != nullptr) stack.push(root);
  
  while (stack.size()) {
    Node* node = stack.top();
    stack.pop();
    values.push_back(node->val);
    if (node->right != nullptr) stack.push(node->right);
    if (node->left != nullptr) stack.push(node->left);
  }
  
  return values;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}