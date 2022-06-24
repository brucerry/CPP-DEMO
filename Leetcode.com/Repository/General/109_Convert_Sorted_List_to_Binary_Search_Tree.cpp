// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time: O(n)
// space: O(log(n))
class Solution {
public:
  ListNode* cur;
  
  TreeNode* sortedListToBST(ListNode* head) {
    cur = head;
    
    int size = 0;
    while (head) {
      head = head->next;
      size++;
    }
    
    return solve(0, size - 1);
  }
  
private:
  TreeNode* solve(int l, int r) {
    if (l > r)
      return nullptr;
    
    int m = l + ((r - l) >> 1);
    
    TreeNode* node = new TreeNode();
    node->left = solve(l, m - 1);
    node->val = cur->val;
    cur = cur->next;
    node->right = solve(m + 1, r);
    
    return node;
  }
};

// time: O(n * log(n))
// space: O(log(n))
class SearchMid {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head)
      return nullptr;
    
    if (!head->next)
      return new TreeNode(head->val);
    
    ListNode* prev = nullptr, *slow = head, *fast = head;
    while (fast and fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    
    prev->next = nullptr;
    
    TreeNode* leftNode = sortedListToBST(head);
    TreeNode* rightNode = sortedListToBST(slow->next);
    
    return new TreeNode(slow->val, leftNode, rightNode);
  }
};