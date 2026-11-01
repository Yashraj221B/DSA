/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> nmap;
        Node* dummy = new Node(0);
        Node* ptr1 = head;
        Node* ptr2 = dummy;
        while(ptr1 != nullptr){
            ptr2->next = new Node(ptr1->val);
            ptr2 = ptr2->next;
            nmap[ptr1] = ptr2;
            ptr1 = ptr1->next;
        }
        ptr1 = head;
        ptr2 = dummy->next;
        while(ptr1 != nullptr){
            if(ptr1->random != nullptr){
                ptr2->random = nmap[ptr1->random];
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return dummy->next;
    }
};