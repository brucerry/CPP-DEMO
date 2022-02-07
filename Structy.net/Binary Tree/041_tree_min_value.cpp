#include <stack>
#include <climits>
#include <algorithm>
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
int treeMinValue(Node* root) {
  if (root == nullptr) return INT_MAX;
  return min({root->val, treeMinValue(root->left), treeMinValue(root->right)});
}



// iterative
int _treeMinValue(Node* root) {
  stack<Node*> stack;
  stack.push(root);
  int min = INT_MAX;
  while (stack.size()) {
    Node* currentNode = stack.top();
    stack.pop();
    if (currentNode->val < min) min = currentNode->val;
    if (currentNode->left != nullptr) stack.push(currentNode->left);
    if (currentNode->right != nullptr) stack.push(currentNode->right);
  }
  return min;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}