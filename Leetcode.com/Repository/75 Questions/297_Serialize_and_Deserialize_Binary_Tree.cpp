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
private:
  void dfsSerialize(TreeNode* node, string& str) {
    if (str.length()) str += ',';
    if (!node) {
      str += 'N';
      return;
    }
    str += to_string(node->val);
    dfsSerialize(node->left, str);
    dfsSerialize(node->right, str);
  }

  TreeNode* dfsDeserialize(vector<string>& values, int* i) {
    if (values[*i] == "N") {
      (*i)++;
      return nullptr;
    }

    TreeNode* node = new TreeNode(stoi(values[*i]));
    (*i)++;

    node->left = dfsDeserialize(values, i);
    node->right = dfsDeserialize(values, i);

    return node;
  }

public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string output;
    dfsSerialize(root, output);
    return output;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<string> values;
    stringstream ss (data);
    string s;
    while (getline(ss, s, ',')) {
      values.emplace_back(s);
    }

    int i = 0;
    return dfsDeserialize(values, &i);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));