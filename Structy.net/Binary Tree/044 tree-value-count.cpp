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



int treeValueCount(Node* root, int targetVal) {
  if (root == nullptr) return 0;
  if (root->val == targetVal) {
    return 1 + treeValueCount(root->left, targetVal) + treeValueCount(root->right, targetVal);
  }
  return treeValueCount(root->left, targetVal) + treeValueCount(root->right, targetVal);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}