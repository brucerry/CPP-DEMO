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



int maxPathSum(Node* root) {
  if (root == nullptr) return INT_MIN;
  if (root->left == nullptr && root->right == nullptr) return root->val;
  return root->val + max(maxPathSum(root->left), maxPathSum(root->right));
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}