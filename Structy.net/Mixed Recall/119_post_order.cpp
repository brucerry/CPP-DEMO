#include <vector>
#include <string>
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



std::vector<std::string> postOrder(Node* root) {
  if (root == nullptr) return {};
  
  vector<string> values;
  
  for (auto leftVal : postOrder(root->left)) {
    values.push_back(leftVal);
  }
  
  for (auto rightVal : postOrder(root->right)) {
    values.push_back(rightVal);
  }
  
  values.push_back(root->val);
  
  return values;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}