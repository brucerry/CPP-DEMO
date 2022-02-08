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



bool binarySearchTreeIncludes(Node* root, int targetVal) {
  if (root == nullptr) return false;
  if (root->val > targetVal) return binarySearchTreeIncludes(root->left, targetVal);
  if (root->val < targetVal) return binarySearchTreeIncludes(root->right, targetVal);
  return true;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}