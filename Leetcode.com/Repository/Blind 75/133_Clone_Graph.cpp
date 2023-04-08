// https://leetcode.com/problems/clone-graph/

#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// time: O(n)
// space: O(n)

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> umap { // real, copy
            { nullptr, nullptr }
        };
        return clone(node, umap);
    }

private:
    Node* clone(Node* real, unordered_map<Node*, Node*>& umap) {
        if (umap.count(real))
            return umap[real];
        Node* copy = new Node(real->val);
        umap[real] = copy;
        for (const auto& nei : real->neighbors) {
            copy->neighbors.push_back(clone(nei, umap));
        }
        return copy;
    }
};