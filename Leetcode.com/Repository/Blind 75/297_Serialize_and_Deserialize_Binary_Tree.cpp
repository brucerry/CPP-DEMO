// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// time: O(n)
// space: O(n)

class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string output;
    dfsSerialize(root, output);
    return output;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss (data);
    string s;
    vector<string> values;
    while (getline(ss, s, ','))
      values.emplace_back(s);
    
    int i = 0;
    return dfsDeserialize(values, i);
  }
  
private:
  TreeNode* dfsDeserialize(vector<string>& values, int& i) {
    if (values[i] == "N") {
      i++;
      return nullptr;
    }
    
    TreeNode* node = new TreeNode(stoi(values[i]));
    i++;
    node->left = dfsDeserialize(values, i);
    node->right = dfsDeserialize(values, i);
    
    return node;
  }
  
  void dfsSerialize(TreeNode* node, string& output) {
    if (output.length())
      output += ',';
    
    if (!node) {
      output += 'N';
      return;
    }
    
    output += to_string(node->val);
    dfsSerialize(node->left, output);
    dfsSerialize(node->right, output);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));