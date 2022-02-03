#include <vector>
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
void leafList(Node* root, vector<string>& result) {
  if (root == nullptr) return;
  if (root->left == nullptr && root->right == nullptr) {
    result.push_back(root->val);
    return;
  }
  
  leafList(root->left, result);
  leafList(root->right, result);
}

std::vector<std::string> leafList(Node* root) {
  vector<string> result;
  leafList(root, result);
  return result;
}




// iterative
std::vector<std::string> _leafList(Node* root) {
  vector<string> result;
  stack<Node*> stack;
  if (root != nullptr) stack.push(root);
  
  while (stack.size()) {
    Node* node = stack.top();
    stack.pop();
    
    if (node->left == nullptr && node->right == nullptr) {
      result.push_back(node->val);
    }
    
    if (node->right != nullptr) stack.push(node->right);
    if (node->left != nullptr) stack.push(node->left);
  }
  
  return result;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}