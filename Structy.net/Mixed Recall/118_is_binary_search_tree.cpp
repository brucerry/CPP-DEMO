#include <vector>
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


void inOrderTraverse(Node* root, vector<int>& values) {
  if (root == nullptr) return;
  
  inOrderTraverse(root->left, values);
  values.push_back(root->val);
  inOrderTraverse(root->right, values);
}


bool isBinarySearchTree(Node* root) {
  vector<int> values;
  inOrderTraverse(root, values);
  return is_sorted(values.begin(), values.end());
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}