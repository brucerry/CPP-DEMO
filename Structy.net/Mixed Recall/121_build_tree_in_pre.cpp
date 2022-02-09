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


Node* buildTreeInPre(std::vector<std::string> inorder, std::vector<std::string> preorder,
                    int startIn, int endIn, int startPre, int endPre) {
  if (startIn > endIn) return nullptr;
  
  string val = preorder[startPre];
  Node* node = new Node(val);
  
  int rootIndex = find(inorder.begin(), inorder.end(), val) - inorder.begin();
  int size = rootIndex - startIn;
  node->left = buildTreeInPre(inorder, preorder, startIn, rootIndex - 1, startPre + 1, startPre + size);
  node->right = buildTreeInPre(inorder, preorder, rootIndex + 1, endIn, startPre + size + 1, endPre);
  return node;
}

Node* buildTreeInPre(std::vector<std::string> inorder, std::vector<std::string> preorder) {
  return buildTreeInPre(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}