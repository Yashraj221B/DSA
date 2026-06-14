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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* ptr = head;
        while(ptr != nullptr){
            n++;
            ptr = ptr->next;
        }
        ptr = head;
        ListNode* tmp;
        for(int i = 0; i < n/2-1; i++){
            ptr = ptr->next;
        }
        ListNode* prev = ptr;
        ListNode* curr = ptr->next;
        ListNode* next = curr->next;
        for(int i = 0; i < n/2-1; i++){
            cout<<curr->val<<" ";
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        return n;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    Solution s = Solution();
    s.pairSum(head);
    return 0;
}
