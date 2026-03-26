#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *ptr = dummy;
        while (l1 != nullptr && l2 != nullptr){
            if (l1->val < l2->val){
                ptr->next = l1;
                l1 = l1->next;
            }else{
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        while (l1 != nullptr)
        {
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
        }
        while (l2 != nullptr)
        {
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
        }
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}
