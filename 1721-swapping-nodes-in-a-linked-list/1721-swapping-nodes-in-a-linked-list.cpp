class Solution {
private:
    int getSize(ListNode* node) {
        int n = 0;
        while (node != nullptr) {
            node = node->next;
            n++;
        }
        return n;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = getSize(head);
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        for (int i = 1; i < k; i++) {
            ptr1 = ptr1->next;
        }
        for (int i = 1; i < len - k + 1; i++) {
            ptr2 = ptr2->next;
        }

        swap(ptr1->val, ptr2->val);

        return head;
    }
};