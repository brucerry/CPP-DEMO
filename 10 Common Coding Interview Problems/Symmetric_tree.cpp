#include <iostream>
using namespace std;

class Node {
public:
  int val;
  Node* left;
  Node* right;

  Node(int value) {
    val = value;
    left = nullptr;
    right = nullptr;
  }
};

/*
  time: O(n)
  space: O(log(n))
*/

bool symmetricTree(Node* root1, Node* root2) {
  if (not root1 and not root2) return true;
  if (root1 and root2 and root1->val == root2->val) return symmetricTree(root1->left, root2->right) and symmetricTree(root2->left, root1->right);
  return false;
}

bool symmetricTree(Node* root) {
  if (not root) return true;
  return symmetricTree(root->left, root->right);
}

int main() {
  Node a(4);
  Node b(5);
  Node c(5);
  Node d(2);
  Node e(8);
  Node f(8);
  Node g(2);
  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.left = &f;
  c.right = &g;
  cout << boolalpha << symmetricTree(&a);
}