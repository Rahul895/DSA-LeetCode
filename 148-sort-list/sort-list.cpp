class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0), *tail = &dummy;

        while (a && b) {
            if (a->val < b->val)
                tail->next = a, a = a->next;
            else
                tail->next = b, b = b->next;

            tail = tail->next;
        }

        tail->next = a ? a : b;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *slow = head, *fast = head->next;

        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;

        ListNode* right = slow->next;
        slow->next = nullptr;

        return merge(sortList(head), sortList(right));
    }
};