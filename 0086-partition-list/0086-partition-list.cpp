/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dum1 = new ListNode();
        ListNode* dum2 = new ListNode();
        auto ptr1 = dum1;
        auto ptr2 = dum2;
        auto ptr = head;
        while(ptr != nullptr){
            if(ptr->val < x){
                ptr1->next = ptr;
                ptr1 = ptr1->next;
            }else{
                ptr2->next = ptr;
                ptr2 = ptr2->next;
            }
            ptr = ptr->next;
        }
        ptr2->next = nullptr;
        ptr1->next = dum2->next;
        return dum1->next;
    }
};