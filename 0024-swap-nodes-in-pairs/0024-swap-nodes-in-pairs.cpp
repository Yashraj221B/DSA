class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode();
        ListNode* ptr1 = dummy;
        ListNode* ptr2 = head;
        ListNode* ptr3 = head->next;    
        while (ptr2 != nullptr && ptr3 != nullptr)
        {
            ptr1->next = ptr3;
            ptr2->next = ptr3->next;
            ptr3->next = ptr2;
            ptr1 = ptr2;
            ptr2 = ptr2->next;
            if (ptr2) ptr3 = ptr2->next;
        }
        return dummy->next;
    }
};