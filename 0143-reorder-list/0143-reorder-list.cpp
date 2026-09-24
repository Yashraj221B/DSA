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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* ptr = head;
        stack<ListNode*> s;
        while(ptr != nullptr){
            s.push(ptr);
            ptr = ptr->next;
            n++;
        }
        ptr = head;
        for(int i = 0; i < n/2; i++){
            s.top()->next = ptr->next;
            ptr->next = s.top();
            ptr = ptr->next->next;
            s.pop();
        }
        ptr->next = nullptr;
    }
};