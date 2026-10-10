#include<bits/stdc++.h>

using namespace std;

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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        for(int i = 0; i < n; i++){
            ptr1 = ptr1->next;
        }
        if(ptr1 == nullptr) {
            ptr2 = ptr2->next;
            delete head;
            return ptr2;
        };
        while(ptr1->next != nullptr){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr2->next->next;
        return head;
    }
};

void printList(ListNode* head){
    while(head != nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    ListNode* h = new ListNode(1, new ListNode(2));
    printList(h);
    Solution s;
    auto u = s.removeNthFromEnd(h,2);
    printList(u);
    return 0;
}
