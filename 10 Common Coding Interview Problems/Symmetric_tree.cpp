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
  if (root1 == nullptr && root2 == nullptr) return true;
  if (root1 == nullptr && root2 != nullptr) return false;
  if (root2 == nullptr && root1 != nullptr) return false;
  if (root1->val != root2->val) return false;
  
  return symmetricTree(root1->left, root2->right) && symmetricTree(root2->left, root1->right);
}

bool symmetricTree(Node* root) {
  if (root == nullptr) return true;
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
  cout << symmetricTree(&a);
}