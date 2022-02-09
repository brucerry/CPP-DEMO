#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Node {
  public:
    std::string val;
    Node* left;
    Node* right;


    Node(std::string initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};


Node* buildTreeInPost(std::vector<std::string> inorder, std::vector<std::string> postorder) {
  if (inorder.size() == 0) return nullptr;
  
  string val = postorder.back();
  Node* node = new Node(val);
  
  auto rootIndex = find(inorder.begin(), inorder.end(), val);
  
  vector<string> inorderLeft (inorder.begin(), rootIndex);
  vector<string> inorderRight (rootIndex + 1, inorder.end());
  vector<string> postorderLeft (postorder.begin(), postorder.begin() + inorderLeft.size());
  vector<string> postorderRight (postorder.begin() + inorderLeft.size(), postorder.end() - 1);
  
  node->left = buildTreeInPost(inorderLeft, postorderLeft);
  node->right = buildTreeInPost(inorderRight, postorderRight);
  return node;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}