#include <climits>
#include <algorithm>
#include <queue>
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


// iterative
int maxPathSum(Node* root) {
  int ans = INT_MIN;
  queue<pair<Node*, int>> queue;
  queue.push({root, root->val});
  
  while (queue.size()) {
    Node* node = queue.front().first;
    int val = queue.front().second;
    queue.pop();
    
    if (node->left == nullptr && node->right == nullptr) ans = max(ans, val);
    
    if (node->left != nullptr) queue.push({node->left, node->left->val + val});
    if (node->right != nullptr) queue.push({node->right, node->right->val + val});
  }
  
  return ans;
}



// recursive
int _maxPathSum(Node* root) {
  if (root == nullptr) return INT_MIN;
  if (root->left == nullptr && root->right == nullptr) return root->val;
  return root->val + max(_maxPathSum(root->left), _maxPathSum(root->right));
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}