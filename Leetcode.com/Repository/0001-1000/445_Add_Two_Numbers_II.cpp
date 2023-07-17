// https://leetcode.com/problems/add-two-numbers-ii/

// time: O(n)
// space: O(1)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverse_list(l1);
        ListNode* r2 = reverse_list(l2);
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int carry = 0;
        while (carry or r1 or r2) {
            int val1 = r1 ? r1->val : 0;
            int val2 = r2 ? r2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            r1 = r1 ? r1->next : r1;
            r2 = r2 ? r2->next : r2;
        }

        return reverse_list(dummy->next);
    }

private:
    ListNode* reverse_list(ListNode* node) {
        ListNode* prev = nullptr, *cur = node;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};