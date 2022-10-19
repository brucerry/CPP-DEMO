// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/


class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// time: O(n)
// space: O(1)
class Iterative {
public:
  Node* connect(Node* root) {
    Node* cur = root, *levelDummy = new Node(), *d = levelDummy;

    while (cur) {
      if (cur->left) {
        d->next = cur->left;
        d = d->next;
      }
      if (cur->right) {
        d->next = cur->right;
        d = d->next;
      }

      cur = cur->next;

      if (!cur) {
        cur = levelDummy->next;
        levelDummy->next = nullptr;
        d = levelDummy;
      }
    }

    return root;
  }
};

// time: O(n)
// space: O(height of tree)
class Recursive {
public:
  Node* connect(Node* root) {
    if (root) {
      if (root->left)
        root->left->next = root->right ? root->right : findNext(root->next);

      if (root->right)
        root->right->next = findNext(root->next);

      connect(root->right);
      connect(root->left);
    }
    return root;
  }

private:
  Node* findNext(Node* node) {
    if (!node)
      return node;
    if (node->left)
      return node->left;
    if (node->right)
      return node->right;
    return findNext(node->next);
  }
};