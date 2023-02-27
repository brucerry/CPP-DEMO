// https://leetcode.com/problems/construct-quad-tree/

#include <vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


// time: O(n^2)
// space: O(log(n))
class Solution1 {
public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, grid.size(), 0, 0);
    }

private:
    Node* solve(vector<vector<int>>& grid, int len, int r, int c) {
        if (len == 1) {
            return new Node(grid[r][c], true);
        }
        Node* node = new Node(grid[r][c], false);
        node->topLeft = solve(grid, len / 2, r, c);
        node->topRight = solve(grid, len / 2, r, c + len / 2);
        node->bottomLeft = solve(grid, len / 2, r + len / 2, c);
        node->bottomRight = solve(grid, len / 2, r + len / 2, c + len / 2);
        if (node->topLeft->isLeaf and node->topRight->isLeaf and node->bottomLeft->isLeaf and node->bottomRight->isLeaf and
            min({ node->topLeft->val, node->topRight->val, node->bottomLeft->val, node->bottomRight->val }) ==
            max({ node->topLeft->val, node->topRight->val, node->bottomLeft->val, node->bottomRight->val })) {
            node->isLeaf = true;
            node->topLeft = node->topRight = node->bottomLeft = node->bottomRight = nullptr;
        }
        return node;
    }
};


// time: O(n^2 * log(n))
// space: O(log(n))
class Solution2 {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        Node* node = new Node();
        solve(grid, node, n, 0, 0);
        return node;
    }

private:
    void solve(vector<vector<int>>& grid, Node* node, int n, int r, int c) {
        auto [ isSame, value ] = isSameValue(grid, r, c, n);
        if (isSame) {
            node->isLeaf = true;
            node->val = value;
            return;
        }
        node->topLeft = new Node();
        node->topRight = new Node();
        node->bottomLeft = new Node();
        node->bottomRight = new Node();
        solve(grid, node->topLeft, n / 2, r, c);
        solve(grid, node->topRight, n / 2, r, c + n / 2);
        solve(grid, node->bottomLeft, n / 2, r + n / 2, c);
        solve(grid, node->bottomRight, n / 2, r + n / 2, c + n / 2);
    }

    pair<bool, int> isSameValue(vector<vector<int>>& grid, int r, int c, int len) {
        int minvalue = 1, maxvalue = 0;
        for (int i = r; i < r + len; i++) {
            for (int j = c; j < c + len; j++) {
                minvalue = min(minvalue, grid[i][j]);
                maxvalue = max(maxvalue, grid[i][j]);
            }
        }
        return { minvalue == maxvalue, minvalue };
    }
};