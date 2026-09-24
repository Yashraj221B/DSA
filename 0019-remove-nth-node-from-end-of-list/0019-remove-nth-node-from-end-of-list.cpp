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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* dummy = new ListNode(0, head);
        ListNode* ptr = dummy;
        while(ptr!=nullptr){
            ptr = ptr->next;
            len++;
        }
        ptr = dummy;
        cout<<len;
        for(int i = 1; i < len-n; i++){
            ptr = ptr->next;
        }
        // unsafe coz no free but it's fine T_T
        ptr->next = ptr->next->next;
        return dummy->next;
    }
};