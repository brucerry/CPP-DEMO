// https://leetcode.com/problems/merge-nodes-in-between-zeros/

// time: O(n)
// space: O(n)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy, *prev = nullptr;
        while (head) {
            if (head->val == 0) {
                cur->next = new ListNode(0);
                prev = cur;
                cur = cur->next;
            }
            else {
                cur->val += head->val;
            }
            head = head->next;
        }
        prev->next = nullptr;
        return dummy->next;
    }
};