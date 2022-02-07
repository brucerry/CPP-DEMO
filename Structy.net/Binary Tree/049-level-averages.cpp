#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Node {
  public:
    float val;
    Node* left;
    Node* right;


    Node(float initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};



std::vector<float> levelAverages(Node* root) {
  vector<float> result;
  vector<vector<float>> values;
  queue<tuple<Node*, int>> queue;
  if (root != nullptr) queue.push({root, 0});
  
  while (queue.size()) {
    auto [ node, level ] = queue.front();
    queue.pop();
    
    if (level < values.size()) {
      values[level].push_back(node->val);
    } else {
      values.push_back({node->val});
    }
    
    if (node->left != nullptr) queue.push({node->left, level+1});
    if (node->right != nullptr) queue.push({node->right, level+1});
  }
  
  for (int i = 0; i < values.size(); i++) {
    float sum = 0;
    for (auto val : values[i]) {
      sum += val;
    }
    result.push_back(sum / values[i].size());
  }
  
  return result;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}