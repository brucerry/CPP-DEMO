#include <stack>
using namespace std;

class Node {
  public:
    int val;
    Node* left;
    Node* right;


    Node(int initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};


// recursive
int treeSum(Node* root) {
  if (root == nullptr) return 0;
  return root->val + treeSum(root->left) + treeSum(root->right);
}


// iterative
int _treeSum(Node* root) {
  stack<Node*> stack;
  int sum = 0;
  if (root != nullptr) stack.push(root);
  while (stack.size()) {
    Node* currentNode = stack.top();
    stack.pop();
    sum += currentNode->val;
    if (currentNode->left != nullptr) stack.push(currentNode->left);
    if (currentNode->right != nullptr) stack.push(currentNode->right);
  }
  return sum;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}