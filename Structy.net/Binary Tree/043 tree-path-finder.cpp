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



std::vector<std::string>* _pathFinder(Node* root, std::string targetVal) {
  if (root == nullptr) return nullptr;
  
  if (root->val == targetVal) return new vector<string> {root->val};
  
  vector<string>* left = _pathFinder(root->left, targetVal);
  if (left != nullptr) {
    left->push_back(root->val);
    return left;
  }
  
  vector<string>* right = _pathFinder(root->right, targetVal);
  if (right != nullptr) {
    right->push_back(root->val);
    return right;
  }
  
  return nullptr;
}


std::vector<std::string>* pathFinder(Node* root, std::string targetVal) {
  vector<string>* result = _pathFinder(root, targetVal);
  if (result != nullptr) {
    reverse(result->begin(), result->end());
  }
  return result;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}