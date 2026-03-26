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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        for(int i = 0; i < k; i++){
            ListNode* ptr1 = head;
            ListNode* ptr2 = head->next;
            while(ptr2->next != nullptr){
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            ptr2->next = head;
            ptr1->next = nullptr;
            head = ptr2;
        }
        return head;
    }
};

void display(ListNode* head){
    while(head != nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    display(head);
    Solution s = Solution();
    s.rotateRight(head, 2000000000);
    display(head);
    return 0;
}
