// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// time: O(n)
// space: O(1)
class Iterative {
public:
  Node* connect(Node* root) {
    if (!root)
      return root;
    
    Node* cur = root, *next = root->left;
    
    while (cur and next) {
      cur->left->next = cur->right;

      if (cur->next)
        cur->right->next = cur->next->left;

      cur = cur->next;
      if (!cur) {
        cur = next;
        next = next->left;
      }
    }
    
    return root;
  }
};

// time: O(n)
// space: O(log(n))
class Recursive {
public:
  Node* connect(Node* root) {
    if (!root or !root->left)
      return root;
    
    populate(root->left, root->right);
    return root;
  }
  
private:
  void populate(Node* leftChild, Node* rightChild) {
    if (!leftChild)
      return;
    
    leftChild->next = rightChild;
    
    populate(leftChild->left, leftChild->right);
    populate(leftChild->right, rightChild->left);
    populate(rightChild->left, rightChild->right);
  }
};