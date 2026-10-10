#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
