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



std::vector<std::vector<std::string>> allTreePaths(Node* root) {
  if (root == nullptr) return {};
  if (root->left == nullptr && root->right == nullptr) return {{root->val}};
  
  vector<vector<string>> result;
  
  for (auto left : allTreePaths(root->left)) {
    left.insert(left.begin(), root->val);
    result.push_back(left);
  }
  
  for (auto right : allTreePaths(root->right)) {
    right.insert(right.begin(), root->val);
    result.push_back(right);
  }
  
  return result;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}