// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time: O(n)
// space: O(1)

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* tmp = dummy;
        for (int i = 0; i < k; i++) {
            tmp = tmp->next;
        }
        ListNode* left = tmp, *right = dummy;
        while (tmp) {
            tmp = tmp->next;
            right = right->next;
        }
        swap(left->val, right->val);
        return dummy->next;
    }
};